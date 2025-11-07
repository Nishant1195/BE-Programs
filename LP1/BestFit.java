import java.util.*;

public class BestFit {
    public static void main(String[] args) {
        int[] blocks = {100, 500, 200, 300, 600};
        int[] processes = {212, 417, 112, 426};

        int[] allocation = new int[processes.length];
        Arrays.fill(allocation, -1);

        for (int i = 0; i < processes.length; i++) {
            int bestIdx = -1;
            for (int j = 0; j < blocks.length; j++) {
                if (blocks[j] >= processes[i]) {
                    if (bestIdx == -1 || blocks[j] < blocks[bestIdx]) {
                        bestIdx = j;
                    }
                }
            }
            if (bestIdx != -1) {
                allocation[i] = bestIdx;
                blocks[bestIdx] -= processes[i];
            }
        }

        System.out.println("\nBest Fit Allocation:");
        System.out.println("Process No.\tProcess Size\tBlock No.");
        for (int i = 0; i < processes.length; i++) {
            System.out.print((i + 1) + "\t\t" + processes[i] + "\t\t");
            if (allocation[i] != -1)
                System.out.println((allocation[i] + 1));
            else
                System.out.println("Not Allocated");
        }
    }
}
