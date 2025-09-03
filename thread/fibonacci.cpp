#include <iostream>
#include <pthread.h>
using namespace std;

// Thread function to generate Fibonacci numbers
void* generateFibonacci(void* arg) {
    int* data = (int*)arg;     // cast back
    int n = data[0];           // first element stores size
    int* arr = data + 1;       // rest of array is for Fibonacci numbers

    if (n >= 1) arr[0] = 0;
    if (n >= 2) arr[1] = 1;

    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return nullptr;
}

int main()
{
    int n;
    cout << "Enter number of Fibonacci numbers: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    // Allocate array of size n + 1
    // data[0] stores size, data[1..n] stores Fibonacci numbers
    int* data = new int[n + 1];
    data[0] = n;

    thread_t thread;
    pthread_create(&thread, nullptr, generateFibonacci, data);

    pthread_join(thread, nullptr);

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << data[i + 1] << " ";
    }
    cout << endl;

    delete[] data;  // free memory
    return 0;
}