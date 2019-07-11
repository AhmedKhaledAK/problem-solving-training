### Note:

This problem is Strongly Connected Components (SCC). It can be solved using Disjoint Sets algorithm for connected components but since the graph is undirected it is much easier to solve it using DFS rather than implementing Disjoint Sets from scratch.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);

        int t = reader.nextInt();
        for (int i = 0; i < t; i++) {
            int n = reader.nextInt(), m = reader.nextInt();
            Graph graph = new Graph(n);
            boolean [] visited = new boolean[n];
            for (int j = 0; j < m; j++)
                graph.addToList(reader.nextInt()-1, reader.nextInt()-1);
            out.print(solve(n, graph, visited));
        }

        out.flush();
    }

    static int solve(int n, Graph graph, boolean[] visited) {
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]) {
                dfs(i, graph, visited);
                cnt++;
            }
        }
        return cnt;
    }

    private static void dfs(int i, Graph graph, boolean[] visited) {
        visited[i] = true;
        if (graph.adjList[i] == null)
            graph.adjList[i] = new LinkedList<>();
        for (int j = 0; j < graph.adjList[i].size(); j++){
            if (!visited[graph.adjList[i].get(j)])
                dfs(graph.adjList[i].get(j), graph, visited);
        }
    }

    static class Graph {
        int size;
        LinkedList<Integer> [] adjList;

        Graph(int size){
            this.size = size;
            adjList = new LinkedList[size];
        }

        void addToList(int x, int y){
            initializeList(x);
            initializeList(y);

            adjList[x].add(y);
            adjList[y].add(x);
        }

        void initializeList(int i) {
            if (adjList[i] == null)
                adjList[i] = new LinkedList<>();
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