import java.util.concurrent.Semaphore;

public class ReaderWriter {
    static int data = 0, readCount = 0;
    static Semaphore mutex = new Semaphore(1);
    static Semaphore rw_mutex = new Semaphore(1);

    static class Reader extends Thread {
        int id;
        Reader(int id) { this.id = id; }
        public void run() {
            try {
                while (true) {
                    mutex.acquire();
                    readCount++;
                    if (readCount == 1) rw_mutex.acquire();
                    mutex.release();

                    System.out.println("Reader " + id + " reads " + data);
                    Thread.sleep(500);

                    mutex.acquire();
                    readCount--;
                    if (readCount == 0) rw_mutex.release();
                    mutex.release();

                    Thread.sleep(500);
                }
            } catch (InterruptedException e) {}
        }
    }

    static class Writer extends Thread {
        int id;
        Writer(int id) { this.id = id; }
        public void run() {
            try {
                while (true) {
                    rw_mutex.acquire();
                    data++;
                    System.out.println("Writer " + id + " writes " + data);
                    Thread.sleep(500);
                    rw_mutex.release();
                    Thread.sleep(1000);
                }
            } catch (InterruptedException e) {}
        }
    }

    public static void main(String[] args) {
        for (int i = 1; i <= 3; i++) new Reader(i).start();
        for (int i = 1; i <= 2; i++) new Writer(i).start();
    }
}