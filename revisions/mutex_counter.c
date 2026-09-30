#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutex;

void* worker(void* arg) {
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < 1000000; i++) {
        counter++;
    }

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[4];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Counter = %d\n", counter);

    return 0;
}