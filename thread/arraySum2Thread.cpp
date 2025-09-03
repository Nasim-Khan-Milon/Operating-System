#include <iostream>
#include <pthread.h>
using namespace std;

// Data structure for each thread
struct ThreadData {
    int* arr;
    int start;
    int end;
};

// Thread function: compute partial sum
void* partial_sum(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int sum = 0;
    for (int i = data->start; i < data->end; i++) {
        sum += data->arr[i];
    }
    int* result = new int(sum);  // allocate result on heap
    return (void*)result;        // return pointer
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    // Fill array with numbers 1..10
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    // Split array into two halves
    ThreadData data1{arr, 0, SIZE / 2};
    ThreadData data2{arr, SIZE / 2, SIZE};

    pthread_t t1, t2;

    // Create two threads
    pthread_create(&t1, nullptr, partial_sum, &data1);
    pthread_create(&t2, nullptr, partial_sum, &data2);

    // Collect results
    void* r1;
    void* r2;
    pthread_join(t1, &r1);
    pthread_join(t2, &r2);

    int* sum1 = (int*)r1;
    int* sum2 = (int*)r2;

    cout << "Sum of first half: " << *sum1 << endl;
    cout << "Sum of second half: " << *sum2 << endl;
    cout << "Total sum: " << *sum1 + *sum2 << endl;

    // Free memory
    delete sum1;
    delete sum2;

    return 0;
}
