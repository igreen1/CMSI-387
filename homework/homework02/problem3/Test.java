import java.util.HashSet;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;


public class Test {
    private static int count;
    private static HashSet<Integer> hashset = new HashSet();
    private static volatile boolean finish = true;

    public static void main(String[] args) throws InterruptedException {
        BoundedBuffer boundedBuffer = new BoundedBuffer();
        ExecutorService exec = Executors.newCachedThreadPool();
        int num_consumer = 10;
        int num_producer = 2;
        int num_product_per_producer = 15;
        int total_product = num_producer * num_product_per_producer;

        for (int i = 0; i < num_producer; ++i) {
            exec.submit(new Runnable() {
                @Override
                public void run() {
                    System.out.println("producer thread starts to run!");
                    for(int j = 0; j < num_product_per_producer; ++j) {
                        try {
                            boundedBuffer.insert(Integer.valueOf(count++));
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            });
        }

        for (int i = 0; i < num_consumer; ++i) {
            exec.submit(new Runnable() {
                @Override
                public void run() {
                    System.out.println("consumer thread starts to run!");
                    while (!Thread.interrupted()) {
                        try {
                            if (hashset.size() == total_product) {
                                //exec.shutdownNow();
                                break;
                            }
                            Integer val = (Integer) boundedBuffer.retrieve();
                            hashset.add(val);
                            //System.out.println(val);
                        } catch (InterruptedException e) {
                            //e.printStackTrace();
                            if (e instanceof InterruptedException) {
                                Thread.currentThread().interrupt();
                            }
                        }
                    }
                }
            });
        }

        exec.shutdown();
        while (!exec.awaitTermination(10, TimeUnit.SECONDS));
        System.out.println("size of hashset:" + hashset.size());
        //System.out.println(hashset);
    }
}
