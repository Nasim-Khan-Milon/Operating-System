#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* threadFunction(void* arg)
{
    int* arr = (int*) arg;
    int size = 5;
    int sum = 0 ;

    cout<<"Thread received array :";
    for(int i=0;i<size; i++)
    {
        cout<<arr[i]<<" "<<flush;
        sum+=arr[i];
        sleep(1);
    }
    cout<<endl;

    // Allocate memory for result so it can be returned
    // int* result =new int(sum);
    // return (void*) result;
    int* result = (int*)malloc(sizeof(int));  // allocate memory for one int
    *result = sum;                            // store the sum in allocated memory
    return (void*)result;                     // return pointer to main
}

int main()
{
    pthread_t thread;

    int arr[5] = {10, 20, 30, 40, 50};

    // Create thread
    pthread_create(&thread, nullptr, threadFunction, arr);

    // Get result back from thread
    void* result;
    pthread_join(thread, &result);

    int* sum = (int*) result;
    cout<<"Sum of the array : "<<*sum<<endl;

    //delete sum;     // Free memory       // ❌ wrong if malloc was used
    free(sum);    // ✅ correct for malloc

    cout << "Main thread exiting" << endl;

    return 0;
}