#include <iostream>
#include <pthread.h>   // for pthread functions
#include <unistd.h>    // for sleep()

using namespace std;

// Function that will be executed by the thread
void* threadFunction(void* arg) {
    cout << "Hello from the thread! Thread ID: " << pthread_self() << endl;
    sleep(1); // simulate some work
    cout << "Thread finishing work..." << endl;
    return nullptr; // thread returns nothing
}

int main() {
    pthread_t thread;  // thread identifier

    // Create a new thread
    if (pthread_create(&thread, nullptr, threadFunction, nullptr) != 0) {
        cerr << "Error creating thread!" << endl;
        return 1;
    }

    cout << "Main thread is waiting for child thread to finish..." << endl;

    // Wait for the thread to finish
    pthread_join(thread, nullptr);

    cout << "Child thread has finished. Main thread exiting." << endl;

    return 0;
}
