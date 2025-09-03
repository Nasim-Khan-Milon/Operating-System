#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void* threadFunction(void* arg)
{
    cout<<"Hello from the thread! Thread ID: "<<pthread_self()<<endl;
    for(int j=0;j<5;j++)
    {
        cout<<j<<endl;
        sleep(1);
    }
    return nullptr;
}

int main()
{
    pthread_t thread;

    if(pthread_create(&thread, nullptr, threadFunction, nullptr) != 0)
    {
        cerr<<"Error creating thread!"<<endl;
        return 1;
    }

    cout<<"Main thread is waiting for child thread to finish...."<<endl;

    pthread_join(thread, nullptr);

    cout<<"Back to the main thread"<<endl;
    for(int i=15;i<=20;i++)
    {
        cout<<i<<endl;
        sleep(1);
    }

    return 0;
}