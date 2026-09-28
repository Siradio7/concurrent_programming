#include <pthread.h>
#include <stdio.h>

void* worker(void* arg) {
    int value = *(int*) arg;
    printf("Received value : %d\n", value);

    return NULL;
}

int main() {
    int value = 42;
    pthread_t thread;

    pthread_create(&thread, NULL, worker, &value);
    pthread_join(thread, NULL);

    return 0;
}