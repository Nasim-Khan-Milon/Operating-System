#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n]; // arrival time, burst time, remaining time
    for(int i = 0; i < n; i++) {
        cout << "Enter arrival time of P" << i+1 << ": ";
        cin >> at[i];
        cout << "Enter burst time of P" << i+1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i]; // initialize remaining time
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    int time = 0, done = 0;
    int wt[n] = {0}, tat[n] = {0};

    while(done < n) {
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                flag = true;
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i] - at[i];
                    tat[i] = time - at[i];
                    rt[i] = 0;
                    done++;
                }
            }
        }
        if(!flag) time++; // no process available, increment time
    }

    cout << "\nPID\tAT\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++)
        cout << i+1 << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";

    return 0;
}
