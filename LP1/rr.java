import java.util.*;

public class RoundRobin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();
        System.out.print("Enter time quantum: ");
        int q = sc.nextInt();

        int[] pid = new int[n];
        int[] at = new int[n];
        int[] bt = new int[n];
        int[] remainingBt = new int[n];
        int[] ct = new int[n];
        int[] tat = new int[n];
        int[] wt = new int[n];
        boolean[] completed = new boolean[n];
        boolean[] inQueue = new boolean[n];

        // Input section
        for (int i = 0; i < n; i++) {
            pid[i] = i + 1;
            System.out.print("Enter arrival time and burst time for process " + pid[i] + ": ");
            at[i] = sc.nextInt();
            bt[i] = sc.nextInt();
            remainingBt[i] = bt[i];
        }

        Queue<Integer> ready = new LinkedList<>();
        int currentTime = 0;
        int completedCount = 0;

        // Scheduling logic
        while (completedCount < n) {
            // Add newly arrived processes to ready queue
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && !completed[i] && at[i] <= currentTime) {
                    ready.add(i);
                    inQueue[i] = true;
                }
            }

            if (!ready.isEmpty()) {
                int idx = ready.poll();
                int execTime = Math.min(q, remainingBt[idx]);
                currentTime += execTime;
                remainingBt[idx] -= execTime;

                // Add newly arrived processes during execution
                for (int i = 0; i < n; i++) {
                    if (!inQueue[i] && !completed[i] && at[i] <= currentTime) {
                        ready.add(i);
                        inQueue[i] = true;
                    }
                }

                if (remainingBt[idx] > 0) {
                    ready.add(idx); // Put back into queue
                } else {
                    completed[idx] = true;
                    ct[idx] = currentTime;
                    tat[idx] = ct[idx] - at[idx];
                    wt[idx] = tat[idx] - bt[idx];
                    completedCount++;
                }
            } else {
                currentTime++; // CPU idle
            }
        }

        // Output section
        System.out.println("\nPID\tAT\tBT\tCT\tTAT\tWT");
        for (int i = 0; i < n; i++) {
            System.out.println(pid[i] + "\t" + at[i] + "\t" + bt[i] + "\t" +
                    ct[i] + "\t" + tat[i] + "\t" + wt[i]);
        }

        sc.close();
    }
}
