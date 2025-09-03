#include <iostream>
#include <pthread.h>
#include<unistd.h>
#include <vector>
using namespace std;

void* threadFunction(void* arg) {
    vector<int>* vec = (vector<int>*)arg;  // cast back
    cout<<"Vector size is "<<vec->size()<<endl;
    cout << "Thread received vector: ";
    for (int val : *vec) {
        cout << val << " "<<flush;
        sleep(1);
    }
    cout << endl;
    return nullptr;
}

int main() {
    pthread_t thread;
    vector<int> nums = {10, 20, 30, 40, 50};

    // Pass address of vector to thread
    pthread_create(&thread, nullptr, threadFunction, &nums);
    pthread_join(thread, nullptr);

    cout << "Main thread exiting" << endl;
    return 0;
}
