```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    static int visit = 0;

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        HashMap<Integer, ArrayList<Integer>> lines = new HashMap<>();
        HashMap<String, Boolean> firstPlace = new HashMap<>();
        int src=-1;
        int N = reader.nextInt();
        do{
            boolean [] visited = new boolean[N+1];
            lines.clear();
            firstPlace.clear();
            String str = br.readLine();
            do{
                String [] split = str.split(" ");
                firstPlace.put(split[0], true);
                ArrayList<Integer> places = new ArrayList<>(100);

                for (int i =0; i < split.length-1; i++) {
                    places.add(Integer.parseInt(split[i+1]));
                    if (firstPlace.get(split[i+1]) == null)
                        src = places.get(i);
                }

                if (lines.get(Integer.parseInt(split[0])) != null){
                    ArrayList<Integer> list = lines.get(Integer.parseInt(split[0]));
                    list.addAll(places);
                    lines.put(Integer.parseInt(split[0]), list);
                } else
                    lines.put(Integer.parseInt(split[0]), places);

                for (Integer place : places) {
                    ArrayList<Integer> list = new ArrayList<>();
                    if (lines.get(place) != null) {
                        list = lines.get(place);
                        list.add(Integer.parseInt(split[0]));
                        lines.put(place, list);
                    } else {
                        list.add(Integer.parseInt(split[0]));
                        lines.put(place, list);
                    }
                }

            }while (!(str = br.readLine()).equals("0"));

            out.println(solve(N, lines, visited, src, out));

        }while ((N = reader.nextInt()) != 0);

        out.flush();
    }

    private static int solve(int n, HashMap<Integer, ArrayList<Integer>> lines, boolean[] visited, int src,
                             PrintWriter out) {
        int critical = 0;
        for (int i = 1; i <= n; i++){
            visit = 0;
            if (i == src) continue;
            visited[i] = true;
            visit++;
            dfs(src, visited, lines, out);
            if (visit != n)
                critical++;
            visited = new boolean[n+1];
        }
        return critical;
    }

    private static void dfs(int src, boolean[] visited, HashMap<Integer, ArrayList<Integer>> lines, PrintWriter out) {
        visited[src] = true;
        visit++;
        ArrayList<Integer> list = lines.get(src);
        for (Integer integer : list) {
            if (!visited[integer])
                dfs(integer, visited, lines, out);
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