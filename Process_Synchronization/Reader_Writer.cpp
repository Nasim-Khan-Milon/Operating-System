#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;       // For updating reader count
pthread_mutex_t writeLock;   // To lock writers

int readCount = 0;           // Number of active readers

void* reader(void* arg) {
    int id = *(int*)arg;

    while(1) {
        // Entry Section for Reader
        pthread_mutex_lock(&mutex);
        readCount++;
        if(readCount == 1) {
            pthread_mutex_lock(&writeLock);   // First reader blocks writers
        }
        pthread_mutex_unlock(&mutex);

        // Critical Section (Reading)
        printf("Reader %d is reading...\n", id);
        sleep(1);

        // Exit Section for Reader
        pthread_mutex_lock(&mutex);
        readCount--;
        if(readCount == 0) {
            pthread_mutex_unlock(&writeLock); // Last reader allows writers
        }
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;

    while(1) {
        pthread_mutex_lock(&writeLock);   // Writer locks all access

        // Critical Section (Writing)
        printf("\tWriter %d is writing...\n", id);
        sleep(2);

        pthread_mutex_unlock(&writeLock); // Writer finishes

        sleep(2);
    }

    return NULL;
}

int main() {
    pthread_t r1, r2, w1;
    int a=1, b=2, c=1;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&writeLock, NULL);

    pthread_create(&r1, NULL, reader, &a);
    pthread_create(&r2, NULL, reader, &b);
    pthread_create(&w1, NULL, writer, &c);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&writeLock);

    return 0;
}
