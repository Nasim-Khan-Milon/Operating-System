#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], rt[n]; // Burst time and remaining time
    for(int i = 0; i < n; i++) {
        cout << "Enter burst time of P" << i+1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i]; // Initialize remaining time
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    int time = 0, done = 0;
    int wt[n] = {0}, tat[n] = {0};

    while(done < n) {
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i]; // Waiting time
                    rt[i] = 0;
                    tat[i] = time;        // Turnaround time
                    done++;
                }
            }
        }
    }

    cout << "\nPID\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++)
        cout << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";

    return 0;
}
