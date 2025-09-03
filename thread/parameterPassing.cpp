#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void* threadFunction (void* arg)
{
    int* ptr = (int*) arg;
    int num = *ptr;

    cout<<"Thread received number: "<<num<<endl;

    for(int i=1;i<=num; i++)
    {
        cout<<i<<endl;
        sleep(1);
    }
    
    return nullptr;
}

int main()
{
    pthread_t thread;

    int value = 5;

    pthread_create(&thread, nullptr, threadFunction, &value);

    pthread_join(thread, nullptr);

    cout<<"Main thread is exiting."<<endl;

    return 0;
}