import java.util.Scanner;

public class FCFS {
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

        // Input
        for (int i = 0; i < n; i++) {
            pid[i] = i + 1;
            System.out.print("Enter arrival time and burst time for process " + pid[i] + ": ");
            at[i] = sc.nextInt();
            bt[i] = sc.nextInt();
        }

        // Sort by arrival time (FCFS rule)
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (at[j] > at[j + 1]) {
                    // swap all related values
                    int temp;

                    temp = at[j];
                    at[j] = at[j + 1];
                    at[j + 1] = temp;

                    temp = bt[j];
                    bt[j] = bt[j + 1];
                    bt[j + 1] = temp;

                    temp = pid[j];
                    pid[j] = pid[j + 1];
                    pid[j + 1] = temp;
                }
            }
        }

        // Calculate completion, turnaround, and waiting times
        int currentTime = 0;
        for (int i = 0; i < n; i++) {
            if (currentTime < at[i]) {
                currentTime = at[i]; // CPU idle until this process arrives
            }
            ct[i] = currentTime + bt[i];
            currentTime = ct[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
        }

        // Output
        System.out.println("\nPID\tAT\tBT\tCT\tTAT\tWT");
        for (int i = 0; i < n; i++) {
            System.out.println(pid[i] + "\t" + at[i] + "\t" + bt[i] + "\t" +
                    ct[i] + "\t" + tat[i] + "\t" + wt[i]);
        }

        sc.close();
    }
}
