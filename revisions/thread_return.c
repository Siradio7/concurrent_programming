#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* worker(void* arg) {
    int value = *(int*) arg;
    int *result = malloc(sizeof(int));

    *result = value + 1;

    return result;
}

int main() {
    int value = 42;
    pthread_t thread;
    void* result;

    pthread_create(&thread, NULL, worker, &value);
    pthread_join(thread, &result);

    printf("Result : %d\n", *(int*) result);
    free(result);

    return 0;
}