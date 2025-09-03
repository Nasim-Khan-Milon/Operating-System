#include <iostream>
#include <pthread.h>
using namespace std;

// Struct to pass data to threads
struct ThreadData {
    int* arr;
    int left;
    int right;
};

// Partition function (last element as pivot)
int partition(int* arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// QuickSort function for thread
void* quickSortThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int left = data->left;
    int right = data->right;
    int* arr = data->arr;

    if (left >= right) return nullptr;

    int pi = partition(arr, left, right);

    // Prepare data for left and right subarrays
    ThreadData leftData{arr, left, pi - 1};
    ThreadData rightData{arr, pi + 1, right};

    pthread_t t1, t2;

    // Create threads for left and right partitions
    pthread_create(&t1, nullptr, quickSortThread, &leftData);
    pthread_create(&t2, nullptr, quickSortThread, &rightData);

    // Wait for both threads
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    return nullptr;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    ThreadData data{arr, 0, n - 1};

    pthread_t mainThread;
    pthread_create(&mainThread, nullptr, quickSortThread, &data);
    pthread_join(mainThread, nullptr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
