#include <iostream>
#include <pthread.h>
#include <unistd.h>   // for sleep()

using namespace std;

// Thread function
void* thread_fun(void* arg) {
    int id = *((int*)arg);  // convert void* back to int
    cout << "Thread " << id << " started! " << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Thread " << id << ": " << i << endl;
        sleep(1); // simulate work
    }

    cout << "Thread " << id << " finished!" << endl;
    return nullptr;
}

int main() {
    const int N = 3;               // number of threads
    pthread_t threads[N];          // array to hold thread IDs
    int ids[N];                    // unique IDs for each thread

    // Create N threads
    for (int i = 0; i < N; i++) {
        ids[i] = i + 1; // IDs = 1, 2, 3
        pthread_create(&threads[i], nullptr, thread_fun, &ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], nullptr);
    }

    cout << "All threads have finished. Main exits." << endl;
    return 0;
}
