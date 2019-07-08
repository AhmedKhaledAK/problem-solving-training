//https://codeforces.com/problemset/problem/288/A
import java.io.*;
import java.security.spec.ECField;
import java.util.HashMap;
import java.util.StringTokenizer;
 
 
 
public class Main {
 
    static int a[];
    static int l[];
    static int ans[];
    static HashMap<Integer, Boolean> map = new HashMap<>();
 
    public static void main (String [] args) throws Exception {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
 
        int n, k;
        n = reader.nextInt();
        k = reader.nextInt();
        int [] str = new int[n];
 
        if(n<k){
            out.println("-1");
            out.flush();
 
            return;
        }
        if(k==1){
            if(n>1)
                out.println("-1");
            else
               out.println("a");
 
            out.flush();
            return;
        }
 
        //char c= 'a'; 97
 
 
        for (int i =0 ; i < (n-k+2) ; i ++)
        {
            if(i<n) {
                if (i % 2 == 0) str[i] = 0;
                else str[i] = 1;
            }
        }
        int j=2;
        for (int i =n-k+2 ; i < n ; i ++)
        {
            str[i]=j++;
        }
 
 
 
        for (int i =0 ; i < n ; i ++)
        {
            out.print( (char) (str[i]+97)  );
        }
 
 
 
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
