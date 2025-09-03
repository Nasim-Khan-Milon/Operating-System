#include<iostream>
#include<pthread.h>
using namespace std;

void* thread_avg(void* arg)
{
    int* arr = (int*) arg;
    int sum = 0;
    int size = 7;

    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    // int avg = sum/size;
    // int* result = new int(avg);
    double avg = (double)sum / size;   // cast to double for accuracy

    double* result = new double(avg);  // allocate memory for double
    return (void*) result;
}

void* thread_max(void* arg)
{
    int* arr = (int*) arg;
    int max = arr[0];
    int size = 7;

    for(int i=1;i<size;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    
    int* result = new int(max);
    return (void*) result;
}

void* thread_min(void* arg)
{
    int* arr = (int*) arg;
    int min = arr[0];
    int size = 7;

    for(int i=1;i<size;i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }
    
    int* result = new int(min);
    return (void*) result;
}

int main()
{
    int size = 7;
    int arr[size]= { 90, 81, 78, 95, 79, 72, 85};
    
    pthread_t t1, t2, t3;

    pthread_create(&t1, nullptr, thread_avg, arr);
    pthread_create(&t2, nullptr, thread_max, arr);
    pthread_create(&t3, nullptr, thread_min, arr);

    void* r1;
    void* r2;
    void* r3;

    pthread_join(t1, &r1);
    pthread_join(t2, &r2);
    pthread_join(t3, &r3);

    double* avg = (double*) r1;
    int* max = (int*) r2;
    int* min = (int*) r3;

    cout<<"The average value is "<<*avg<<endl;
    cout<<"The maximum value is "<<*max<<endl;
    cout<<"The minimum value is "<<*min<<endl;

    delete avg;
    delete max;
    delete min;

    return 0;
}