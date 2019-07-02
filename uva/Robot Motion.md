```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);


        String str = br.readLine();
        do {
            String[] splits = str.split(" ");
            int tRows = Integer.parseInt(splits[0]), tCols = Integer.parseInt(splits[1]),
                    sCol = Integer.parseInt(splits[2]);
            char[][] matrix = new char[tRows][tCols];
            boolean[][] vMatrix = new boolean[tRows][tCols];

            for (int i = 0; i < tRows; i++) {
                str = br.readLine();
                for (int j = 0; j < tCols; j++) {
                    matrix[i][j] = str.charAt(j);
                }
            }

            calculateSteps(tRows, tCols, sCol, matrix, vMatrix, out);

        } while (!(str = br.readLine()).equals("0 0 0"));


        out.flush();
    }

    private static void calculateSteps(int tRows, int tCols, int sCol, char[][] matrix, boolean[][] vMatrix,
                                       PrintWriter out) {
        int row = 0, col = sCol - 1, cnt = 0, lpcnt = 0, nolpcnt = 0;
        int vRow = -1, vCol = -1;
        Pair p;
        while (row >= 0 && row <= tRows - 1 && col >= 0 && col <= tCols - 1) {
            cnt++;
            if (!vMatrix[row][col]) {
                vMatrix[row][col] = true;
                char c = matrix[row][col];
                p = updateRowsAndCols(c, row, col);
                row = p.row;
                col = p.col;
            } else {
                vRow = row;
                vCol = col;
                break;
            }
        }

        if (vRow != -1) {
            p = updateRowsAndCols(matrix[vRow][vCol], vRow, vCol);
            int r = p.row;
            int c = p.col;

            while (r != vRow || c != vCol){
                lpcnt++;
                char d = matrix[r][c];
                p = updateRowsAndCols(d, r, c);
                r = p.row;
                c = p.col;
            }
            nolpcnt = --cnt - ++lpcnt;
            out.println(nolpcnt + " step(s) before a loop of " + lpcnt + " step(s)");
        } else {
            out.println(cnt + " step(s) to exit");
        }
    }

    private static Pair updateRowsAndCols(char c, int row, int col) {
        if (c == 'W') col--;
        else if (c == 'E') col++;
        else if (c == 'N') row--;
        else if (c == 'S') row++;
        return new Pair(row, col);
    }

    static class  Pair {
        int row, col;
        Pair(int row, int col){
            this.col = col;
            this.row = row;
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
}
```

