#include <iostream>
using namespace std;

int main()
{
    int n = 4;                // number of processes
    int bt[4] = {2, 4, 3, 5}; // burst times
    int wt[4], tat[4];        // waiting time, turnaround time
    float avg_wt = 0, avg_tat = 0;

    // first process
    wt[0] = 0;
    tat[0] = bt[0];

    // calculate WT and TAT for remaining processes
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    cout << "Process\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
        cout << "P" << i + 1 << "\t"
            << bt[i] << "\t"
            << wt[i] << "\t"
            << tat[i] << endl;
    }

    avg_wt /= n;
    avg_tat /= n;
    cout << "\nAverage Waiting Time = " << avg_wt << endl;
    cout << "Average Turnaround Time = " << avg_tat << endl;

    return 0;
}
