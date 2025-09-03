#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void* threadFunction(void* arg)
{
    int* arr = (int*) arg;
    int size = 5;

    cout<<"Thread received array:"<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" "<<flush;
        sleep(1);
    }
    cout<<endl;

    return nullptr;
}

int main()
{
    pthread_t thread;

    int arr[5] = {10, 20, 30, 40, 50};

    pthread_create(&thread, nullptr, threadFunction, arr);
    pthread_join(thread, nullptr);

    cout<<"Main thread exiting"<<endl;

    return 0;
}