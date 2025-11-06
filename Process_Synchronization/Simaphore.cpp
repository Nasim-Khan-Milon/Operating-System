#include <pthread.h>   // For pthread_create, pthread_join
#include <stdio.h>     // For printf
#include <unistd.h>    // For sleep
#include <semaphore.h> // For sem_t, sem_init, sem_wait, sem_post, sem_destroy

int sharedMemory = 1; // Shared variable accessed by both threads
sem_t sm;             // Binary semaphore to protect sharedMemory

// Thread 1: Increments sharedMemory
void* thread1(void*) {
    sem_wait(&sm);       // Wait (lock) the semaphore before entering critical section

    int x = sharedMemory;   // Read sharedMemory into local variable
    printf("Thread 1 reads: %d\n", x);

    x++;                    // Increment local copy
    printf("Thread 1 increments to: %d\n", x);

    sleep(1);               // Simulate delay/context switch

    sharedMemory = x;       // Write back to sharedMemory
    printf("Thread 1 updates sharedMemory to: %d\n", sharedMemory);

    sem_post(&sm);          // Release (unlock) the semaphore
    return NULL;            // Exit thread
}

// Thread 2: Decrements sharedMemory
void* thread2(void*) {
    sem_wait(&sm);       // Wait (lock) semaphore

    int x = sharedMemory;   // Read sharedMemory
    printf("Thread 2 reads: %d\n", x);

    x--;                    // Decrement local copy
    printf("Thread 2 decrements to: %d\n", x);

    sleep(1);               // Simulate delay/context switch

    sharedMemory = x;       // Write back to sharedMemory
    printf("Thread 2 updates sharedMemory to: %d\n", sharedMemory);

    sem_post(&sm);          // Release (unlock) semaphore
    return NULL;            // Exit thread
}

int main() {
    sem_init(&sm, 0, 1);    // Initialize semaphore
                             // 0 = shared between threads
                             // 1 = initial value (binary semaphore)

    pthread_t th1, th2;     // Declare thread variables

    // Create threads
    pthread_create(&th1, NULL, thread1, NULL);
    pthread_create(&th2, NULL, thread2, NULL);

    // Wait for both threads to finish
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    // Print final value of sharedMemory
    printf("Final sharedMemory = %d\n", sharedMemory);

    sem_destroy(&sm);        // Destroy semaphore
    return 0;
}
