#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];   // Shared buffer
int in = 0, out = 0;       // Indexes for producer and consumer
int count = 0;             // Number of items in buffer

pthread_mutex_t lock;      // Mutex for critical section

// Producer thread
void* producer(void*) {
    int item = 1;
    while (true) {
        pthread_mutex_lock(&lock);   // Lock mutex

        if (count < BUFFER_SIZE) {   // Check for empty slot
            buffer[in] = item;
            printf("Producer produced: %d at %d\n", item, in);
            in = (in + 1) % BUFFER_SIZE;
            count++;
            item++;
        }

        pthread_mutex_unlock(&lock); // Unlock mutex
        sleep(1);                    // Slow down for demonstration
    }
}

// Consumer thread
void* consumer(void*) {
    while (true) {
        pthread_mutex_lock(&lock);   // Lock mutex

        if (count > 0) {             // Check for full slot
            int item = buffer[out];
            printf("\tConsumer consumed: %d from %d\n", item, out);
            out = (out + 1) % BUFFER_SIZE;
            count--;
        }

        pthread_mutex_unlock(&lock); // Unlock mutex
        sleep(1);                    // Slow down for demonstration
    }
}

int main() {
    pthread_t prod, cons;

    pthread_mutex_init(&lock, NULL);  // Initialize mutex

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&lock);     // Destroy mutex
    return 0;
}
