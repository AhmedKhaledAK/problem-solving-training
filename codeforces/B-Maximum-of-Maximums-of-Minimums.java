import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class Main {
 
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        //InputStreamReader isr = new InputStreamReader(System.in);
        //BufferedReader br = new BufferedReader(isr);
 
        int n = reader.nextInt(), k = reader.nextInt();
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int first = -1;
        int last = -1;
        for (int i = 0; i < n; i++){
            int a = reader.nextInt();
            if (k == 1) {
                if (a < min) {
                    min = a;
                }
            }else if (k!=2){
                if (a > max){
                    max = a;
                }
            }else {
                if (i == 0)
                    first = a;
                if (i == n-1)
                    last = a;
                if (a < min){
                    min = a;
                }
            }
        }
 
        if (k == 1)
            out.print(min);
        else if(k!=2)
            out.print(max);
        else {
            if (first > last)
                out.print(first);
            else
                out.print(last);
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
 
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
