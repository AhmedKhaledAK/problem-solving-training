```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        
        int t = reader.nextInt();
        for (int i = 0; i < t; i++){
            int n = reader.nextInt(), m = reader.nextInt();
            boolean[]visited = new boolean[n];
            LinkedList<Integer> [] adjList = new LinkedList[n];
            for (int j = 0; j < m; j++)
                addToList(reader.nextInt() - 1, reader.nextInt() - 1, adjList);
            out.println(solve(n,m,adjList,visited));
        }

        out.flush();
    }

    static int solve(int n, int m, LinkedList<Integer>[] adjList, 
                     boolean[] visited) {
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                cnt = 0;
                ans = max(ans, dfs(i, adjList,visited));
            }
        }
        return ans;
    }

    static int dfs(int i, LinkedList<Integer>[] adjList, boolean[] visited) {
        visited[i] = true;
        cnt++;
        for (int j = 0; j < adjList[i].size(); j++){
            if (!visited[adjList[i].get(j)])
                dfs(adjList[i].get(j), adjList,visited);
        }
        return cnt;
    }

    static int max(int ans, int dfs){
        return ans > dfs ? ans : dfs;
    }

    static void addToList(int u, int v, LinkedList<Integer>[] adjList) {
        initializeList(u, adjList);
        initializeList(v, adjList);

        adjList[u].add(v);
        adjList[v].add(u);
    }

    static void initializeList(int i, LinkedList<Integer>[] adjList) {
        if (adjList[i] == null)
            adjList[i] = new LinkedList();
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

