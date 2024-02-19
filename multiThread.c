#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 4

int sharedData = 0;
pthread_mutex_t mutex;
pthread_barrier_t barrier;

void* threadFunction(void* arg) {
    int n = *(int*)arg;

    // Wait until all threads are ready to start
    pthread_barrier_wait(&barrier);

    // Critical section (protected by a mutex)
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < n; i++) {
        // Your thread's logic here
    }
    printf("%d times looped with multithreading.\n", n);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int threadData[THREAD_COUNT] = {1000, 100, 10, 1};

    pthread_mutex_init(&mutex, NULL);
    pthread_barrier_init(&barrier, NULL, THREAD_COUNT + 1);  // Additional +1 for the main thread

    printf("-----------------\n");

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, threadFunction, &threadData[i]);
    }

    // Wait for all threads to be created
    pthread_barrier_wait(&barrier);

    // Release the barrier to start all threads simultaneously
    pthread_barrier_destroy(&barrier);

    // Wait for all threads to finish
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
