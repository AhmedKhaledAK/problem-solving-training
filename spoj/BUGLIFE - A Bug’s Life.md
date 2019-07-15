``` java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static long minGlobal = Long.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();

        int t = reader.nextInt();
        for (int i = 1; i <= t; i++){
            int b = reader.nextInt(), n = reader.nextInt();
            LinkedList<Integer>[] adj = new LinkedList[b];
            int[] color = new int[b];
            for (int k = 0; k < b; k++)
                color[k] = -1;
            for (int j = 0; j < n; j++)
                insert(reader.nextInt() - 1, reader.nextInt() - 1, adj);

            if(solve(b, color,adj,out)){
                out.printf("Scenario #%d:\nNo suspicious bugs found!\n", i);
            }else {
                out.printf("Scenario #%d:\nSuspicious bugs found!\n", i);
            }
        }

        out.flush();
    }

    static boolean solve(int b, int[] color, LinkedList<Integer>[] adj) {
        for (int i = 0; i < b; i++)
            if (color[i] == -1)
                if (!bipartite(i,color,adj))
                    return false;
        return true;
    }

    static boolean bipartite(int i, int[] color, LinkedList<Integer>[] adj) {
        color[i] = 1;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(i);
        while (!queue.isEmpty()){
            int v = queue.poll();
            for (int j = 0; j < adj[v].size(); j++){
                if (adj[v].get(j) == v)
                    return false;
                if (color[adj[v].get(j)] == -1){
                    color[adj[v].get(j)] = 1 - color[v];
                    queue.add(adj[v].get(j));
                }else if(color[adj[v].get(j)] == color[v])
                    return false;
            }
        }
        return true;
    }

    static void insert(int i, int j, LinkedList<Integer>[] adj) {
        initList(i,adj);
        initList(j,adj);
        adj[i].add(j);
        adj[j].add(i);
    }

    static void initList(int j, LinkedList<Integer>[] adj) {
        if (adj[j] == null)
            adj[j] = new LinkedList<>();
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

