```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);

        int t = reader.nextInt();
        for (int i = 0; i < t; i++) {
            int n = reader.nextInt(), m = reader.nextInt();
            LinkedList<Edge> edges = new LinkedList<>();
            boolean[][] isEdgeTaken = new boolean[n][n];
            boolean[][] isEdgeRemoved = new boolean[n][n];
            DisjointSets sets = new DisjointSets(n);
            for (int j = 0; j < m; j++)
                edges.add(new Edge(reader.nextInt() - 1, reader.nextInt() - 1,
                                   reader.nextInt()));

            solve(n, m, edges, isEdgeTaken, isEdgeRemoved, sets, out);
        }

        out.flush();
    }

    static void solve(int n, int m, LinkedList<Edge> edges, 
                      boolean[][] isEdgeTaken, boolean[][] isEdgeRemoved,
                      DisjointSets sets, PrintWriter out) {
        int sol1 = mst(n, edges, sets, isEdgeRemoved, isEdgeTaken, true);
        int sol2 = Integer.MAX_VALUE;
        for (int i = 0; i < m; i++){
            Edge edge = edges.get(i);
            if (isEdgeTaken[edge.src][edge.dest]){
                isEdgeRemoved[edge.src][edge.dest] = true;
                sol2 = min(sol2, mst(n, edges, sets, isEdgeRemoved, isEdgeTaken,
                                     false));
                isEdgeRemoved[edge.src][edge.dest] = false;
            }
        }
        if(sol2 == Integer.MAX_VALUE)
            out.println(sol1 + " " + sol1);
        else
            out.println(sol1 + " " + sol2);
    }

    static int min(int sol2, int mst) {
        return sol2 > mst ? mst : sol2;
    }

    static int mst(int n, LinkedList<Edge> edges, DisjointSets sets, 
                   boolean[][] isEdgeRemoved,
                   boolean[][] isEdgeTaken, boolean s) {
        int sum = 0;
        if (s)
            Collections.sort(edges);
        sets = new DisjointSets(n);
        for (int i = 0; i < n; i++)
            sets.makeSet(i);

        for (Edge edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            if (isEdgeRemoved[u][v]) continue;
            if (sets.findSet(u) != sets.findSet(v)) {
                sum += edge.weight;
                sets.union(u, v);
                if (s)
                    isEdgeTaken[u][v] = true;
            }
        }
        if (sets.sets != 1)
            return Integer.MAX_VALUE;
        return sum;
    }

    static class Edge implements Comparable<Edge> {

        int src, dest;
        Integer weight;

        Edge(int src, int dest, Integer weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return this.weight.compareTo(o.weight);
        }
    }

    static class DisjointSets {

        int[] parent;
        int[] rank;
        int maxNumOfSets;
        int sets;

        DisjointSets(int size) {
            this.sets = size;
            this.maxNumOfSets = size;
            this.parent = new int[maxNumOfSets];
            this.rank = new int[maxNumOfSets];

            for (int i = 0; i < size; i++) {
                parent[i] = -1;
                rank[i] = -1;
            }
        }

        void makeSet(int v) {
            parent[v] = v;
            rank[v] = 0;
        }

        void link(int repX, int repY) {
            if (repX == repY) return;
            if (rank[repX] > rank[repY])
                parent[repY] = repX;
            else {
                parent[repX] = repY;
                if (rank[repX] == rank[repY])
                    rank[repY] += 1;
            }
            sets--;
        }

        int findSet(int v) {
            if (v == -1)
                return -1;
            if (v != parent[v])
                parent[v] = findSet(parent[v]);
            return parent[v];
        }

        void union(int v1, int v2) {
            int repX = findSet(v1);
            int repY = findSet(v2);
            if (repX != -1 && repY != -1) link(repX, repY);
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

