#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_WAITING 50
#define NUM_PASSENGERS 100

int i = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bus_arrived = PTHREAD_COND_INITIALIZER;
pthread_cond_t bus_departed = PTHREAD_COND_INITIALIZER;

int riders_waiting = 0;
int riders_boarded = 0;

void *bus_thread(void *arg) {
    while (i <= NUM_PASSENGERS) {
        pthread_mutex_lock(&mutex);
        while (riders_waiting == 0 && i <= NUM_PASSENGERS) {
            pthread_cond_wait(&bus_arrived, &mutex);
        }
        if (i <= NUM_PASSENGERS) {
            riders_boarded = riders_waiting > MAX_WAITING ? MAX_WAITING : riders_waiting;
            riders_waiting -= riders_boarded;
            printf("Bus is boarding %d passengers\n", riders_boarded);
        }
        pthread_cond_broadcast(&bus_departed);
        pthread_mutex_unlock(&mutex);
    }
    printf("All passengers boarded; bus departing\n");
    return NULL;
}

void *passenger_thread(void *arg) {
    pthread_mutex_lock(&mutex);
    while (riders_waiting >= MAX_WAITING && i <= NUM_PASSENGERS) {
        pthread_cond_wait(&bus_departed, &mutex);
    }
    riders_waiting++;
    printf("Passenger %d boarded\n", i++);
    pthread_cond_signal(&bus_arrived);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t bus, passengers[NUM_PASSENGERS];
    pthread_create(&bus, NULL, bus_thread, NULL);
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        pthread_create(&passengers[i], NULL, passenger_thread, NULL);
    }
    pthread_join(bus, NULL);
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        pthread_join(passengers[i], NULL);
    }
    return 0;
}
