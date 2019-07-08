```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int[] row = {-1, 1, 0, 0};
    static int[] col = {0, 0, -1, 1};

    public static void main(String[] args) {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        
        int t = reader.nextInt();
        for (int k = 0; k < t; k++) {
            int r = reader.nextInt(), c = reader.nextInt();
            PriorityQueue<Element> queue = new PriorityQueue<>();
            int [][] sp = new int[r][c];

            for (int i = 0; i < r; i++) {
                String s = reader.next();
                for (int j = 0; j < c; j++) {
                    if (s.charAt(j) == '0')
                        sp[i][j] = Integer.MAX_VALUE;
                    else
                        sp[i][j] = 0;
                    queue.add(new Element(i, j, sp[i][j]));
                }
            }
            bfs(r, c, queue, sp, out);
        }

        out.flush();
    }

    private static void bfs(int r, int c, PriorityQueue<Element> queue, 
                            int[][] sp, PrintWriter out) {
        while (!queue.isEmpty()) {
            Element curr = queue.poll();
            if(curr.d != sp[curr.i][curr.j]) continue;
            for (int k = 0; k < 4; k++) {
                int i = curr.i + row[k];
                int j = curr.j + col[k];
                if (checkChild(r, c, i, j))
                    if (curr.d + 1 < sp[i][j]) {
                        sp[i][j] = curr.d + 1;
                        queue.add(new Element(i, j, sp[i][j]));
                    }
            }
        }
        print(sp,out,r,c);
    }

    private static boolean checkChild(int r, int c, int i, int j) {
        return i >= 0 && i <= r - 1 && j >= 0 && j <= c - 1;
    }

    private static void print(int[][] arr, PrintWriter out, int r, int c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c-1; j++)
                out.print(arr[i][j] + " ");
            out.println(arr[i][c-1]);
        }
    }

    static class Element implements Comparable<Element> {
        int i, j;
        Integer d;

        Element(int i, int j, Integer d) {
            this.i = i;
            this.j = j;
            this.d = d;
        }

        @Override
        public int compareTo(Element o) {
            return this.d.compareTo(o.d);
        }
    }


    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
```

