#include <stdio.h>
#include <pthread.h>

#define NB_THREADS 2
#define NB_INCREMENTATION 1000000

int counterA = 0;
int counterB = 0;

pthread_mutex_t mutexA;
pthread_mutex_t mutexB;

typedef struct {
    int* compteur;
    pthread_mutex_t* mutex;
} ThreadArgs;

void* worker(void* arg) {
    ThreadArgs* args = (ThreadArgs*) arg;

    for (int i = 0; i < NB_INCREMENTATION; i++) {
        pthread_mutex_lock(args->mutex);

        (*args->compteur)++;

        pthread_mutex_unlock(args->mutex);
    }

    return NULL;
}

int main() {
    pthread_t threads[NB_THREADS];

    pthread_mutex_init(&mutexA, NULL);
    pthread_mutex_init(&mutexB, NULL);

    ThreadArgs argsA = { &counterA, &mutexA };
    ThreadArgs argsB = { &counterB, &mutexB };

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_create(&threads[i], NULL, worker, i == 0 ? &argsA : &argsB);
    }

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutexA);
    pthread_mutex_destroy(&mutexB);

    printf("Counter A = %d\n", counterA);
    printf("Counter B = %d\n", counterB);

    return 0;
}