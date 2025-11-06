#include <pthread.h>   // For pthread_create, pthread_join, pthread_mutex_t
#include <stdio.h>     // For printf
#include <unistd.h>    // For sleep

int sharedMemory = 1;           // Shared variable
pthread_mutex_t lock;           // Mutex lock

// Thread 1: Increment sharedMemory
void* thread1(void*) {
    pthread_mutex_lock(&lock);  // Lock mutex before entering critical section

    int x = sharedMemory;       
    printf("Thread 1 reads: %d\n", x);

    x++;                       
    printf("Thread 1 increments to: %d\n", x);

    sleep(1);                  // Simulate delay

    sharedMemory = x;          
    printf("Thread 1 updates sharedMemory to: %d\n", sharedMemory);

    pthread_mutex_unlock(&lock); // Unlock mutex after critical section
    return NULL;
}

// Thread 2: Decrement sharedMemory
void* thread2(void*) {
    pthread_mutex_lock(&lock);  // Lock mutex

    int x = sharedMemory;
    printf("Thread 2 reads: %d\n", x);

    x--;                       
    printf("Thread 2 decrements to: %d\n", x);

    sleep(1);                  // Simulate delay

    sharedMemory = x;          
    printf("Thread 2 updates sharedMemory to: %d\n", sharedMemory);

    pthread_mutex_unlock(&lock); // Unlock mutex
    return NULL;
}

int main() {
    pthread_t th1, th2;                  // Thread variables

    pthread_mutex_init(&lock, NULL);     // Initialize mutex

    // Create threads
    pthread_create(&th1, NULL, thread1, NULL);
    pthread_create(&th2, NULL, thread2, NULL);

    // Wait for threads to finish
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("Final sharedMemory = %d\n", sharedMemory);

    pthread_mutex_destroy(&lock);        // Destroy mutex
    return 0;
}
