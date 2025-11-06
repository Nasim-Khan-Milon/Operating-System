#include <iostream>
#include <pthread.h>
#include <unistd.h>  // for sleep(1)
using namespace std;

int sharedMemory = 1;  // Shared resource

void* thread1(void*) {   // Must return void* for pthread
    int x = sharedMemory;
    cout << "Thread 1: Read sharedMemory = " << x << endl;

    x++; // increment in register
    cout << "Thread 1: Incremented value in register = " << x << endl;

    sleep(1); // force context switch

    sharedMemory = x;
    cout << "Thread 1: Updated sharedMemory = " << sharedMemory << endl;

    return NULL;
}

void* thread2(void*) {
    int x = sharedMemory;
    cout << "Thread 2: Read sharedMemory = " << x << endl;

    x--; // decrement in register
    cout << "Thread 2: Decremented value in register = " << x << endl;

    sleep(1); // force context switch

    sharedMemory = x;
    cout << "Thread 2: Updated sharedMemory = " << sharedMemory << endl;

    return NULL;
}

int main() {
    cout << "Main thread started.\n";

    pthread_t th1, th2;

    pthread_create(&th1, NULL, thread1, NULL);
    pthread_create(&th2, NULL, thread2, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    cout << "\nFinal value of sharedMemory = " << sharedMemory << endl;

    return 0;
}
