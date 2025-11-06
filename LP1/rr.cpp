#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, q;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> q;

    int pid[n], at[n], bt[n], remaining_bt[n], ct[n], tat[n], wt[n];
    bool completed[n] = {false};

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter arrival time and burst time for process " << pid[i] << ": ";
        cin >> at[i] >> bt[i];
        remaining_bt[i] = bt[i];
    }

    queue<int> ready;
    int current_time = 0, completed_count = 0;
    bool inQueue[n] = {false};

    // start with first process that arrives
    while (completed_count < n) {
        // push newly arrived processes
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && !completed[i] && at[i] <= current_time) {
                ready.push(i);
                inQueue[i] = true;
            }
        }

        if (!ready.empty()) {
            int idx = ready.front();
            ready.pop();

            int exec_time = min(q, remaining_bt[idx]);
            current_time += exec_time;
            remaining_bt[idx] -= exec_time;

            // check newly arrived processes during execution
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && !completed[i] && at[i] <= current_time) {
                    ready.push(i);
                    inQueue[i] = true;
                }
            }

            if (remaining_bt[idx] > 0) {
                ready.push(idx); // put back into queue
            } else {
                completed[idx] = true;
                ct[idx] = current_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                completed_count++;
            }
        } else {
            current_time++; // if no process in queue, idle
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i]
             << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    return 0;
}
