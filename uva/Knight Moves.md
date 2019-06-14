# Note:

This solution is still not complete as the original input in UVA needs to be mapped. You can do it with several ways using string parsing and manipulation methods. I am just too lazy now, will be back at it later.

From: a b c d e f g h
To:      0 1 2 3 4 5 6 7

From: 1 2 3 4 5 6 7 8
To:       0 1 2 3 4 5 6 7

If there is any problems, please create an issue or edit it in a pull request. 

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    private static int N = 8;

    public static void main(String[] args) {

        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);

        Vertex [][] vertices = new Vertex[8][8];

        for(int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                vertices[i][j] = new Vertex(i,j);
                vertices[i][j].setVisited(false);
                vertices[i][j].setOrder(Integer.MAX_VALUE);
            }
        }

        int cSource = reader.nextInt(), rSource = reader.nextInt(), cDest = reader.nextInt(), rDest = reader.nextInt();

        bfs(vertices, cSource, rSource);

        out.println(vertices[rDest][cDest].getDistance());
        out.flush();
    }

    private static void bfs(Vertex[][] vertices, int cSource, int rSource) {
        vertices[rSource][cSource].setOrder(0);
        vertices[rSource][cSource].setDistance(0);
        vertices[rSource][cSource].setVisited(true);
        PriorityQueue<Vertex> queue = new PriorityQueue<>();
        queue.add(vertices[rSource][cSource]);

        int [] xMove = {2, 1, -1, -2, -2, -1, 1, 2};
        int [] yMove = {1, 2, 2, 1, -1, -2, -2, -1};

        int order = 1;

        while (!queue.isEmpty()){
            Vertex v = queue.poll();
            for (int k = 0; k < 8; k++){
                int x = v.getI() + xMove[k];
                int y = v.getJ() + yMove[k];

                if (isSafe(x,y)) {
                    if (!vertices[x][y].isVisited()) {
                        vertices[x][y].setVisited(true);
                        vertices[x][y].setDistance(vertices[v.getI()][v.getJ()].getDistance() + 1);
                        vertices[x][y].setOrder(order++);
                        queue.add(vertices[x][y]);
                    }
                }

            }
        }

    }


    private static boolean isSafe(int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < N);
    }

    static class Vertex implements Comparable<Vertex> {

        private int i, j;
        private int distance;
        private boolean visited;
        private Integer order;


        @Override
        public int compareTo(Vertex vertex) {
            return this.getOrder().compareTo(vertex.getOrder());
        }


        Vertex(int i, int j){
            this.i = i;
            this.j = j;
        }

        int getDistance() {
            return distance;
        }

        void setDistance(int distance) {
            this.distance = distance;
        }

        int getI() {
            return i;
        }

        int getJ() {
            return j;
        }

        boolean isVisited() {
            return visited;
        }

        void setVisited(boolean visited) {
            this.visited = visited;
        }

        Integer getOrder() {
            return order;
        }

        void setOrder(Integer order) {
            this.order = order;
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