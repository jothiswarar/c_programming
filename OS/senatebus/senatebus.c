#include <stdio.h>
#include <pthread.h>

#define MAX_WAITING 5
#define NUM_PASSENGERS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bus_arrived = PTHREAD_COND_INITIALIZER;
pthread_cond_t bus_departed = PTHREAD_COND_INITIALIZER;

int riders_waiting = 0;
int riders_boarded = 0;
int all_passengers_boarded = 0;

void *bus_thread(void *arg) {
    while (!all_passengers_boarded) {
        pthread_mutex_lock(&mutex);

        // Wait for the bus to arrive or all passengers to have boarded
        while (riders_waiting == 0 && !all_passengers_boarded) {
            pthread_cond_wait(&bus_arrived, &mutex);
        }

        if (!all_passengers_boarded) {
            // Board passengers
            riders_boarded = riders_waiting > MAX_WAITING ? MAX_WAITING : riders_waiting;
            riders_waiting -= riders_boarded;

            printf("Bus is boarding %d passengers\n", riders_boarded);

            // Notify passengers that the bus has departed
            pthread_cond_broadcast(&bus_departed);
        }

        pthread_mutex_unlock(&mutex);
    }
    printf("All passengers boarded; bus departing\n");
    return NULL;
}

void *passenger_thread(void *arg) {
    pthread_mutex_lock(&mutex);

    // Wait for the bus to arrive or all passengers to have boarded
    while (riders_waiting >= MAX_WAITING && !all_passengers_boarded) {
        pthread_cond_wait(&bus_departed, &mutex);
    }

    if (!all_passengers_boarded) {
        // Board the bus
        riders_waiting++;
        printf("Passenger boarded\n");

        // Notify the bus that a passenger has boarded
        pthread_cond_signal(&bus_arrived);
    } else {
        printf("Passenger didn't board; bus departed\n");
    }

    // Check if all passengers have boarded
    if (riders_waiting == 0) {
        all_passengers_boarded = 1;
    }

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t bus, passengers[NUM_PASSENGERS];

    pthread_create(&bus, NULL, bus_thread, NULL);

    // Create passenger threads
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        pthread_create(&passengers[i], NULL, passenger_thread, NULL);
    }

    // Join threads
    pthread_join(bus, NULL);
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        pthread_join(passengers[i], NULL);
    }

    return 0;
}
