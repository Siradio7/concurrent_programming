#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void* myThread(void* arg){
    printf("secondary thread\n");
    int* res = (int *) malloc(sizeof(int));
    
    *res = *(int*)arg + 1;

    return res;
}

int main(int argc, char** argv){
    pthread_t thread1;
    int arg = 0;

    pthread_create(&thread1, NULL, myThread, &arg);
    printf("main thread\n");

    void* result; 

    pthread_join(thread1, &result);
    printf("result=%d\n", *((int*)result));
    free(result); // beware of memory leaks!

    return 0;
}