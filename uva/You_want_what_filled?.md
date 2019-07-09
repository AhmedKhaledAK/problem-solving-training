```java
package abc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static int[] row = {-1, 1, 0, 0};
    static int[] col = {0, 0, -1, 1};
    static ArrayList<Hole> list = new ArrayList<>(25000);
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = reader.nextInt(), m = reader.nextInt();
        int t = 0;
        do {
            t++;
            boolean[][] visited = new boolean[n][m];
            char[][] matrix = new char[n][m];
            list = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                String s = reader.next();
                for (int j = 0; j < m; j++) {
                    if (s.charAt(j) == '.')
                        visited[i][j] = true;
                    matrix[i][j] = s.charAt(j);
                }
            }

            solve(n, m, visited, matrix);

            Collections.sort(list);

            out.println("Problem: " + t);
            for (int i = list.size() -1; i >= 0; i--){
                Hole hole = list.get(i);
                out.println(hole.c + " " + hole.size);
            }

        } while ((n = reader.nextInt()) != 0 && (m = reader.nextInt()) != 0);

        out.flush();
    }

    private static void solve(int n, int m, boolean[][] visited, 
                              char[][] matrix) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt = 1;
                if (!visited[i][j]) {
                    dfs(n, m, i, j, visited, matrix);
                    list.add(new Hole(matrix[i][j], cnt));
                }
            }
        }
    }

    private static void dfs(int n, int m, int i, int j, 
                            boolean[][] visited, char[][] matrix) {
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];
            if (checkChild(n, m, ni,nj)) {
                if (!visited[ni][nj]) {
                    if (matrix[ni][nj] == matrix[i][j]) {
                        cnt++;
                        dfs(n, m, ni, nj, visited, matrix);
                    }
                }
            }
        }
    }

    private static boolean checkChild(int r, int c, int i, int j) {
        return i >= 0 && i <= r - 1 && j >= 0 && j <= c - 1;
    }


    static class Hole implements Comparable<Hole> {
        Character c;
        Integer size;


        Hole(Character c, Integer size) {
            this.c = c;
            this.size = size;
        }

        @Override
        public int compareTo(Hole o) {
            if (this.size.compareTo(o.size) == 0)
                return o.c.compareTo(this.c);
            return this.size.compareTo(o.size);
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

