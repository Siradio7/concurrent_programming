#include <stdio.h>
#include <pthread.h>

#define NB_TRANSFERS 1000

int accountA = 1000;
int accountB = 1000;

pthread_mutex_t mutexA;
pthread_mutex_t mutexB;

void transfer(int *from, int *to, int amount) {
    
    pthread_mutex_lock(&mutexA);
    pthread_mutex_lock(&mutexB);

    *from -= amount;
    *to += amount;

    pthread_mutex_unlock(&mutexB);
    pthread_mutex_unlock(&mutexA);
}

void* worker1(void* arg) {
    for (int i = 0; i < NB_TRANSFERS; i++) {
        transfer(&accountA, &accountB, 100);
    }

    return NULL;
}

void* worker2(void* arg) {
    for (int i = 0; i < NB_TRANSFERS; i++) {
        transfer(&accountB, &accountA, 50);
    }

    return NULL;
}

int main() {
    pthread_t thread1;
    pthread_t thread2;

    pthread_mutex_init(&mutexA, NULL);
    pthread_mutex_init(&mutexB, NULL);

    pthread_create(&thread1, NULL, worker1, NULL);
    pthread_create(&thread2, NULL, worker2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutexA);
    pthread_mutex_destroy(&mutexB);

    printf("Account A = %d\n", accountA);
    printf("Account B = %d\n", accountB);
    printf("Total = %d\n", accountA + accountB);

    return 0;
}