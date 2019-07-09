#### Note:

This problem can be solved using Disjoint Sets algorithm for connected components, but since it is an undirected graph, it is much easier to solve it using DFS rather than implementing disjoint sets from scratch.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static boolean[] visited = new boolean[26];

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        int t = reader.nextInt();
        out.println();
        out.flush();
        for (int i = 0; i < t; i++) {
            String lrgstNode = reader.next();
            char c = lrgstNode.charAt(0);
            int size = c - 65 + 1;
            LinkedList<Integer>[] adjList = new LinkedList[size];
            String str = br.readLine();
            do {
                char src = str.charAt(0);
                char dest = str.charAt(1);
                addToGraph(src, dest, adjList);

                str = br.readLine();
            } while (str.length() != 0);
            out.println(solve(adjList, size));
            visited = new boolean[26];
        }
        out.flush();
    }

    private static int solve(LinkedList<Integer>[] adjList, int size) {
        int cnt = 0;
        for (int i = 0; i < size; i++){
            if (!visited[i]){
                dfs(i, adjList);
                cnt++;
            }
        }
        return cnt;
    }

    private static void dfs(int i, LinkedList<Integer>[] adjList) {
        visited[i] = true;
        for (int j = 0; j < adjList[i].size(); j++){
            if (!visited[adjList[i].get(j)])
                dfs(adjList[i].get(j), adjList);
        }
    }

    private static void addToGraph(char src, char dest, 
                                   LinkedList<Integer>[] adjList) {
        initializeList(src, dest, adjList);
        adjList[src - 65].add(dest - 65);
        adjList[dest - 65].add(src - 65);
    }

    private static void initializeList(char src, char dest, 
                                       LinkedList<Integer>[] adjList) {
        if (adjList[src - 65] == null)
            adjList[src - 65] = new LinkedList<>();
        if (adjList[dest - 65] == null)
            adjList[dest - 65] = new LinkedList<>();
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

