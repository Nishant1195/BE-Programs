import java.util.*;

public class SJFNonPreemptive {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        int[] pid = new int[n];
        int[] at = new int[n];
        int[] bt = new int[n];
        int[] ct = new int[n];
        int[] tat = new int[n];
        int[] wt = new int[n];
        boolean[] completed = new boolean[n];

        // Input section
        for (int i = 0; i < n; i++) {
            pid[i] = i + 1;
            completed[i] = false;
            System.out.print("Enter arrival time and burst time for process " + pid[i] + ": ");
            at[i] = sc.nextInt();
            bt[i] = sc.nextInt();
        }

        int completedCount = 0;
        int currentTime = 0;

        // Scheduling logic
        while (completedCount < n) {
            int idx = -1;
            int minBt = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                if (!completed[i] && at[i] <= currentTime && bt[i] < minBt) {
                    minBt = bt[i];
                    idx = i;
                }
            }

            if (idx != -1) {
                currentTime += bt[idx];
                ct[idx] = currentTime;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                completed[idx] = true;
                completedCount++;
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
