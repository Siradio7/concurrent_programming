#include <pthread.h>
#include <stdio.h>

void* worker(void* arg) {
    printf("Worker thread \n");

    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, worker, NULL);
    printf("Main thread\n");
    pthread_join(thread, NULL);

    return 0;
}