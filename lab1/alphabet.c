#include <pthread.h>
#include <stdio.h>

void *print_char(void *arg) {
    printf("%c", *(char*)arg);
    return NULL;
}

int main() {
    char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    pthread_t theads[26];

    for (int i = 0; i < 26; i++) {
        pthread_create(&theads[i], NULL, print_char, &letters[i]);
    }

    for (int i = 0; i < 26; i++) {
        pthread_join(theads[i], NULL);
    }
    
    return 0;
}