```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    static int[] row = {-1, 1, 0, 0};
    static int[] col = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = reader.nextInt();
        int m = reader.nextInt();

        boolean[][] visited = new boolean[n][m];
        char[][] bw = new char[n][m];

        for (int i = 0; i < n; i++) {
            String s = reader.next();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == '-') {
                    visited[i][j] = true;
                    bw[i][j] = '-';
                }
            }
        }

        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!visited[i][j]) {
                    bw[i][j] = 'B';
                    dfs(i,j,n,m,visited,bw);
                }
            }
        }

        for (int i =0; i < n; i++){
            for (int j = 0; j <m; j++){
                out.print(bw[i][j]);
            }
            out.println();
        }

        out.flush();
    }

    private static void dfs(int srci, int srcj, int n, int m, 
                            boolean[][] visited, char[][] bw) {
        visited[srci][srcj] = true;
        for (int i = 0; i < 4; i++) {
            int ni = srci + row[i];
            int nj = srcj + col[i];
            if (checkChild(n, m, ni, nj)) {
                if (!visited[ni][nj]) {
                    if (bw[srci][srcj] == 'B') bw[ni][nj] = 'W';
                    else bw[ni][nj] = 'B';
                    dfs(ni,nj,n,m,visited,bw);
                }
            }
        }
    }

    private static boolean checkChild(int r, int c, int i, int j) {
        return i >= 0 && i <= r - 1 && j >= 0 && j <= c - 1;
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

