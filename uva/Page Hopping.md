``` java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.NumberFormat;
import java.util.PriorityQueue;

public class Main {

    static int N = 100;
    static boolean[][] matrix = new boolean[N + 1][N + 1];
    static boolean[] isFound = new boolean[N + 1];
    static boolean[] isVisited = new boolean[N + 1];
    static int[] distance = new int[N + 1];
    static int sum = 0;
    static int vert = 0;

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        String str = br.readLine();
        int cases = 1;
        do {
            sum = 0;
            vert = 0;
            isFound = new boolean[N+1];
            matrix = new boolean[N+1][N+1];
            String[] strings = str.split(" ");

            for (int i = 0; i < strings.length - 2; i++) {
                insertInMatrix(Integer.valueOf(strings[i]), Integer.valueOf(strings[i + 1]));
                i += 1;
            }

            for (int i = 0; i < N + 1; i++) {
                if (isFound[i])
                    bfs(i);
            }

            double avgLen = sum*1.0/(vert*(vert - 1));
            NumberFormat nf = NumberFormat.getInstance();
            nf.setMinimumFractionDigits(3);
            out.println("Case " + cases + ": average length between pages = " + nf.format(avgLen) + " clicks");

        } while (!(str = br.readLine()).equals("0 0"));
        out.flush();
    }

    private static void bfs(int i) {
        isVisited[i] = true;
        PriorityQueue<Integer> queue = new PriorityQueue<>(100);
        queue.add(i);
        while (!queue.isEmpty()) {
            int v = queue.poll();
            for (int j = 1; j < N + 1; j++) {
                if (matrix[v][j] && !isVisited[j]) {
                    isVisited[j] = true;
                    distance[j] = distance[v] + 1;
                    sum += distance[j];
                    queue.add(j);
                }
            }
        }
        isVisited = new boolean[N+1];
        distance = new int[N+1];
    }

    private static void insertInMatrix(int src, int dest) {
        matrix[src][dest] = true;

        if (!isFound[src])
            vert++;
        if (!isFound[dest])
            vert++;

        isFound[src] = true;
        isFound[dest] = true;
    }
}
```

