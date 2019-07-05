```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {


    static int L = 4;

    public static void main(String[] args) {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);


        int t = reader.nextInt();
        int[] initial = new int[L];
        int[] target = new int[L];
        int[] forbid = new int[L];
        HashMap<String, Boolean> visited = new HashMap<>(10000);
        HashMap<String, Integer> position = new HashMap<>();
        for (int i = 0; i < t; i++) {

            for (int j = 0; j < L; j++)
                initial[j] = reader.nextInt();

            for (int j = 0; j < L; j++)
                target[j] = reader.nextInt();

            int f = reader.nextInt();
            for (int j = 0; j < f; j++) {
                for (int k = 0; k < L; k++) {
                    forbid[k] = reader.nextInt();
                    visited.put(Arrays.toString(forbid), true);
                }
                forbid = new int[L];
            }

            out.println(solve(initial, target, visited, position));
            visited.clear();
            position.clear();
        }

        out.flush();
    }

    static int solve(int[] initial, int[] target, HashMap<String, Boolean> visited,
                             HashMap<String, Integer> position) {
        Queue<int[]> queue = new LinkedList<>();
        position.put(Arrays.toString(initial), 0);
        visited.put(Arrays.toString(initial), false);
        queue.add(initial);
        boolean isTargetFound = false;
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            String cs = Arrays.toString(curr);
            if (visited.get(cs) != null && visited.get(cs)) continue;
            visited.put(cs, true);
            if (cs.equals(Arrays.toString(target))) {
                isTargetFound = true;
                break;
            }
            int[] child = Arrays.copyOf(curr, L);
            for (int i = 0; i < L; i++) {
                child[i] += 1;
                child[i] %= 10;
                String chs = Arrays.toString(child);
                if (visited.get(chs) == null || !visited.get(chs))
                    queue.add(child);
                position.put(chs, position.get(cs) + 1);
                child = Arrays.copyOf(curr, L);
            }
            for (int i = 0; i < L; i++) {
                child[i] -= 1;
                if (child[i] == -1) child[i] = 9;
                String chs = Arrays.toString(child);
                if (visited.get(chs) == null || !visited.get(chs))
                    queue.add(child);
                position.put(chs, position.get(cs) + 1);
                child = Arrays.copyOf(curr, L);
            }
        }

        return isTargetFound ? position.get(Arrays.toString(target)) : -1;
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