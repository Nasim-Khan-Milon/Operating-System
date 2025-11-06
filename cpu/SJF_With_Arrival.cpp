#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n = 4;
    int at[4] = {0, 1, 2, 3}; // arrival times
    int bt[4] = {8, 4, 2, 1}; // burst times
    int rt[4];                // remaining times
    int wt[4] = {0}, tat[4] = {0};
    float avg_wt = 0, avg_tat = 0;

    // copy burst times to remaining times
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int complete = 0, t = 0, min_rt, shortest = -1;
    bool found;

    while (complete < n)
    {
        min_rt = INT_MAX;
        found = false;

        // Find process with minimum remaining time at this time t
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min_rt)
            {
                min_rt = rt[i];
                shortest = i;
                found = true;
            }
        }

        if (!found)
        {
            t++; // no process ready, advance time
            continue;
        }

        // Execute process for 1 time unit
        rt[shortest]--;
        t++;

        // If process finished
        if (rt[shortest] == 0)
        {
            complete++;
            int finish_time = t;
            tat[shortest] = finish_time - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            avg_wt += wt[shortest];
            avg_tat += tat[shortest];
        }
    }

    cout << "Process\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;

    avg_wt /= n;
    avg_tat /= n;
    cout << "\nAverage Waiting Time = " << avg_wt << endl;
    cout << "Average Turnaround Time = " << avg_tat << endl;

    return 0;
}
