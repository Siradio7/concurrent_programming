#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int myGlobalVar = 0;

struct cell {
    int val;
};

struct cell* new_cell(int n){
    struct cell* res = (struct cell *) malloc(sizeof(struct cell));
    res->val = n;

    return res;
}

void* myThread(void* arg){
    int myLocalVar = 0;
    struct cell* c = (struct cell*) arg;

    myLocalVar++;
    myGlobalVar++;
    c->val++;
    printf("myLocalVar==%d, myGlobalVar==%d, c->val==%d\n", myLocalVar, myGlobalVar, c->val);

    return NULL;
}

int main(int argc, char** argv){
    pthread_t thread1;
    struct cell* c = new_cell(0);

    pthread_create(&thread1, NULL, myThread, c);
    myThread(c);
    pthread_join(thread1, NULL);
    
    return 0;
}