#include <stdio.h>
#include <pthread.h>

#define NB_THREADS 2

int counter = 0;
pthread_mutex_t mutex;

void* worker(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t threads[NB_THREADS];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Counter = %d\n", counter);

    return 0;
}