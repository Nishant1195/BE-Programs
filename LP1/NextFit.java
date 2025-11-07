import java.util.*;

public class NextFit {
    public static void main(String[] args) {
        int[] blocks = {100, 500, 200, 300, 600};
        int[] processes = {212, 417, 112, 426};

        int[] allocation = new int[processes.length];
        Arrays.fill(allocation, -1);

        int j = 0;
        int lastAllocated = 0;

        for (int i = 0; i < processes.length; i++) {
            int count = 0;
            while (count < blocks.length) {
                if (blocks[j] >= processes[i]) {
                    allocation[i] = j;
                    blocks[j] -= processes[i];
                    lastAllocated = j;
                    break;
                }
                j = (j + 1) % blocks.length;
                count++;
            }
        }

        System.out.println("\nNext Fit Allocation:");
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
