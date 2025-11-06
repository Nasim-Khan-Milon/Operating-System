#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;

const int N = 5; // Number of philosophers
mutex forks[N];   // One mutex per fork

void philosopher(int id) {
    while (true) {
        cout << "Philosopher " << id << " is thinking.\n";
        this_thread::sleep_for(chrono::seconds(1));

        // Deadlock-free fork picking:
        if (id % 2 == 0) {
            forks[id].lock();                     // left fork
            forks[(id + 1) % N].lock();           // right fork
        } else {
            forks[(id + 1) % N].lock();           // right fork
            forks[id].lock();                     // left fork
        }

        // Eating
        cout << "Philosopher " << id << " is eating.\n";
        this_thread::sleep_for(chrono::seconds(2));

        // Put down forks
        forks[id].unlock();
        forks[(id + 1) % N].unlock();

        cout << "Philosopher " << id << " finished eating and is thinking again.\n";
    }
}

int main() {
    vector<thread> philosophers;

    // Create philosopher threads
    for (int i = 0; i < N; i++) {
        philosophers.push_back(thread(philosopher, i));
    }

    // Join threads (infinite loop, won't actually join)
    for (auto &t : philosophers) {
        t.join();
    }

    return 0;
}
