#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10
#define NB_THREADS 2
#define NB_SWAPS 1000000

int a[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
pthread_mutex_t lock[SIZE];

void swap(int i, int j) {
    if (i == j) {
        return;
    }

    int first = i < j ? i : j;
    int second = i < j ? j : i;

    pthread_mutex_lock(&lock[first]);
    pthread_mutex_lock(&lock[second]);

    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    pthread_mutex_unlock(&lock[second]);
    pthread_mutex_unlock(&lock[first]);
}

void checkIntegrity() {
    int seen[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        if (a[i] < 0 || a[i] >= SIZE) {
            printf("ERROR: invalid value %d at index %d\n", a[i], i);
            return;
        }

        seen[a[i]]++;
    }

    for (int i = 0; i < SIZE; i++) {
        if (seen[i] != 1) {
            printf("ERROR: value %d appears %d times\n", i, seen[i]);
            return;
        }
    }

    printf("Array integrity: OK\n");
}

void* myThread(void* arg) {
    for (int i = 0; i < NB_SWAPS; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        swap(x, y);
    }

    return NULL;
}


int main() {
    pthread_t threads[NB_THREADS];

    for (int i = 0; i < SIZE; i++) {
        pthread_mutex_init(&lock[i], NULL);
    }

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_create(&threads[i], NULL, myThread, NULL);
    }

    for (int i = 0; i < NB_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    checkIntegrity();

    for (int i = 0; i < SIZE; i++) {
        pthread_mutex_destroy(&lock[i]);
    }

    return 0;
}