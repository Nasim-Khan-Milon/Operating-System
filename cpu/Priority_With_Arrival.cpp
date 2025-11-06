#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid, at, bt, priority, wt, tat, ct;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[n];

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival time of P" << i+1 << ": ";
        cin >> p[i].at;
        cout << "Enter burst time of P" << i+1 << ": ";
        cin >> p[i].bt;
        cout << "Enter priority of P" << i+1 << ": ";
        cin >> p[i].priority;
    }

    int time = 0, completed = 0;
    bool done[n] = {0};

    while(completed < n) {
        int idx = -1, highest = 1e9;
        for(int i = 0; i < n; i++) {
            if(!done[i] && p[i].at <= time && p[i].priority < highest) {
                highest = p[i].priority;
                idx = i;
            }
        }
        if(idx == -1) { time++; continue; }

        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        done[idx] = true;
        completed++;
    }

    cout << "\nPID\tAT\tBT\tPriority\tWT\tTAT\n";
    for(int i = 0; i < n; i++)
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].priority 
             << "\t\t" << p[i].wt << "\t" << p[i].tat << "\n";

    return 0;
}
