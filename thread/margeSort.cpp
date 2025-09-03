#include <iostream>
#include <pthread.h>
using namespace std;

// Struct to pass data to thread
struct ThreadData {
    int* arr;
    int left;
    int right;
};

// Merge function
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Thread function for MergeSort
void* mergeSortThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int left = data->left;
    int right = data->right;
    int* arr = data->arr;

    if (left >= right) return nullptr;

    int mid = left + (right - left) / 2;

    // Prepare data for left and right threads
    ThreadData leftData{arr, left, mid};
    ThreadData rightData{arr, mid + 1, right};

    pthread_t t1, t2;

    // Sort left and right halves in separate threads
    pthread_create(&t1, nullptr, mergeSortThread, &leftData);
    pthread_create(&t2, nullptr, mergeSortThread, &rightData);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    // Merge sorted halves
    merge(arr, left, mid, right);

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
    pthread_create(&mainThread, nullptr, mergeSortThread, &data);
    pthread_join(mainThread, nullptr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
