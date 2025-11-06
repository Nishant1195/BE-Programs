#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], pr[n], ct[n], tat[n], wt[n];
    bool completed[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        completed[i] = false;
        cout << "Enter arrival time, burst time, and priority for process " << pid[i] << ": ";
        cin >> at[i] >> bt[i] >> pr[i];
    }

    int completed_count = 0, current_time = 0;

    while (completed_count < n) {
        int idx = -1;
        int highest_priority = 100000; // Lower value means higher priority

        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= current_time && pr[i] < highest_priority) {
                highest_priority = pr[i];
                idx = i;
            }
        }

        if (idx != -1) {
            current_time += bt[idx];
            ct[idx] = current_time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed[idx] = true;
            completed_count++;
        } else {
            current_time++;
        }
    }

    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    return 0;
}
