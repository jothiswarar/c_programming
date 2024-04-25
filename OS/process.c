#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Function to be executed by the first thread
void *thread1(void *arg)
{
    printf("Hello from thread 1!\n");
    return NULL;
}

// Function to be executed by the second thread
void *thread2(void *arg)
{
    printf("Hello from thread 2!\n");
    return NULL;
}

int main()
{
    // Create two threads
    pthread_t thread1_id, thread2_id;
    pthread_create(&thread1_id, NULL, thread1, NULL);
    pthread_create(&thread2_id, NULL, thread2, NULL);

    // Wait for the threads to finish
    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);

    return 0;
}
