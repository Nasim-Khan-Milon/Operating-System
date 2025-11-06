#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid, bt, priority, wt, tat;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter burst time of P" << i+1 << ": ";
        cin >> p[i].bt;
        cout << "Enter priority of P" << i+1 << ": ";
        cin >> p[i].priority;
    }

    // Sort processes by priority (lower value = higher priority)
    sort(p.begin(), p.end(), [](Process a, Process b){ return a.priority < b.priority; });

    int sum_bt = 0;
    float total_wt = 0, total_tat = 0;

    for(auto &proc : p) {
        sum_bt += proc.bt;
        proc.tat = sum_bt;
        proc.wt = proc.tat - proc.bt;
        total_wt += proc.wt;
        total_tat += proc.tat;
    }

    cout << "\nPID\tBT\tPriority\tWT\tTAT\n";
    for(auto proc : p)
        cout << proc.pid << "\t" << proc.bt << "\t" << proc.priority << "\t\t" 
             << proc.wt << "\t" << proc.tat << "\n";

    cout << "\nAverage WT = " << total_wt/n << "\n";
    cout << "Average TAT = " << total_tat/n << "\n";

    return 0;
}
