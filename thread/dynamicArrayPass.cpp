#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void* threadFunction(void* arg)
{
    int* data = (int*) arg;
    int size = data[0];

    cout<<"Thread received dymanic array : "<<endl;

    for(int i=1;i<=size;i++)
    {
        cout<<data[i]<<" "<<flush;
        sleep(1);
    }
    cout<<endl;

    return nullptr;
}

int main()
{
    pthread_t thread;

    int n;
    cout<<"Enter size of array :";
    cin>>n;

    int* data = (int*)malloc((n+1) * sizeof(int));
    //int data[n+1];
    data[0] = n;

    cout<<"Enter the array element :";
    for(int i=1; i<=n;i++)
    {
        cin>>data[i];
    }

    pthread_create(&thread, nullptr, threadFunction, data);
    pthread_join(thread, nullptr);

    cout<<"Main thread exiting"<<endl;

    free(data);

    return 0;
}