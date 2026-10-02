#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NB_THREADS 2

int counter = 0;
pthread_mutex_t mutexA;
pthread_mutex_t mutexB;

void* worker1(void* arg) {
    pthread_mutex_lock(&mutexA);

    sleep(1);

    pthread_mutex_lock(&mutexB);

    for (int i = 0; i < 1000000; i++) {
        counter++;
    }

    pthread_mutex_unlock(&mutexB);
    pthread_mutex_unlock(&mutexA);

    return NULL;
}

void* worker2(void* arg) {
    pthread_mutex_lock(&mutexA);

    sleep(1);

    pthread_mutex_lock(&mutexB);

    for (int i = 0; i < 1000000; i++) {
        counter++;
    }

    pthread_mutex_unlock(&mutexB);
    pthread_mutex_unlock(&mutexA);

    return NULL;
}

int main() {
    pthread_t threads[NB_THREADS];

    pthread_mutex_init(&mutexA, NULL);
    pthread_mutex_init(&mutexB, NULL);

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_create(&threads[i], NULL, i == 0 ? worker1 : worker2, NULL);
    }

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutexA);
    pthread_mutex_destroy(&mutexB);

    printf("Counter = %d\n", counter);

    return 0;
}