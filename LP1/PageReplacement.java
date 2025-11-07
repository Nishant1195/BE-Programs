import java.util.*;

public class PageReplacement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of frames: ");
        int frames = sc.nextInt();

        System.out.print("Enter number of pages: ");
        int n = sc.nextInt();

        int pages[] = new int[n];
        System.out.println("Enter page reference string:");
        for (int i = 0; i < n; i++)
            pages[i] = sc.nextInt();

        Set<Integer> s = new HashSet<>(frames);
        Queue<Integer> q = new LinkedList<>();

        int pageFaults = 0;

        for (int page : pages) {
            if (!s.contains(page)) {
                if (s.size() == frames) {
                    int oldest = q.poll();
                    s.remove(oldest);
                }
                s.add(page);
                q.add(page);
                pageFaults++;
            }
        }

        System.out.println("\nTotal Page Faults = " + pageFaults);
        sc.close();
    }
}
