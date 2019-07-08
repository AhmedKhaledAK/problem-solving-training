//https://codeforces.com/problemset/problem/735/C
import java.io.*;
import java.net.Socket;
import java.security.spec.ECField;
import java.util.HashMap;
import java.util.StringTokenizer;
import static java.util.Arrays.sort;
 
 
public class Main {
 
    static int a[];
    static int l[];
    static int arr[];
    static int ans[];
    static HashMap<Integer, Boolean> map = new HashMap<>();
 
    public static void main (String [] args) throws Exception {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
 
        long n, k;
 
        n = reader.nextLong();
 
 
        long c=1;
        long prev=2;
        long post=1;
        long fib=2;
        while(fib<= n){
            fib = prev + post;
            c++;
            post=prev;
            prev=fib;
        }
 
        out.println(c-1);
 
        out.flush();
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
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
