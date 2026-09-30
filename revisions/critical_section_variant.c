#include <stdio.h>
#include <pthread.h>

#define NB_THREADS 2

int counter = 0;
pthread_mutex_t mutex;

// Avec cette version le thread a le lock jusqu'à la fin de son éxécution
void* worker(void* arg) {
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < 1000000; i++) {
        counter++;
    }
    
    pthread_mutex_unlock(&mutex);

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