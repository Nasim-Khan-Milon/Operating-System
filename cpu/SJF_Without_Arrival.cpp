#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int bt[4] = {6, 8, 7, 3}; // burst times
    int wt[4], tat[4];
    float avg_wt = 0, avg_tat = 0;
    int pid[4];

    // Initialize process IDs
    for (int i = 0; i < n; i++)
        pid[i] = i + 1;

    // Sort processes by burst time (SJF)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    // First process
    wt[0] = 0;
    tat[0] = bt[0];

    // Calculate WT and TAT for remaining processes
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
        cout << "P" << pid[i] << "\t"
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
