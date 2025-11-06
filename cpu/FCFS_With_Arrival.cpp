#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int at[4] = {5, 1, 6, 2}; // arrival times
    int bt[4] = {2, 4, 3, 5}; // burst times
    int wt[4], tat[4], ct[4], pid[4];
    float avg_wt = 0, avg_tat = 0;

    // Initialize process IDs
    for (int i = 0; i < n; i++)
        pid[i] = i + 1;

    // Sort processes by arrival time using simple selection sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time < at[i])
            time = at[i]; // CPU idle
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
        cout << "P" << pid[i] << "\t"
            << at[i] << "\t"
            << bt[i] << "\t"
            << ct[i] << "\t"
            << tat[i] << "\t"
            << wt[i] << endl;

    avg_wt /= n;
    avg_tat /= n;
    cout << "\nAverage Waiting Time = " << avg_wt << endl;
    cout << "Average Turnaround Time = " << avg_tat << endl;

    return 0;
}
