#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5  // Number of philosophers

pthread_mutex_t forks[N];  // Mutex for each fork

void *philosopher(void *num) {
    int id = *(int *)num;

    while(1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        // Pick up forks (mutex lock)
        pthread_mutex_lock(&forks[id]);               // left fork
        pthread_mutex_lock(&forks[(id + 1) % N]);     // right fork

        // Eating
        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        // Put down forks (mutex unlock)
        pthread_mutex_unlock(&forks[id]);            
        pthread_mutex_unlock(&forks[(id + 1) % N]);  

        printf("Philosopher %d finished eating and is thinking again.\n", id);
    }
}

int main() {
    pthread_t thread_id[N];
    int phil_ids[N];

    // Initialize mutexes
    for(int i=0; i<N; i++)
        pthread_mutex_init(&forks[i], NULL);

    // Create philosopher threads
    for(int i=0; i<N; i++) {
        phil_ids[i] = i;
        pthread_create(&thread_id[i], NULL, philosopher, &phil_ids[i]);
    }

    // Join threads (never happens here)
    for(int i=0; i<N; i++)
        pthread_join(thread_id[i], NULL);

    return 0;
}
