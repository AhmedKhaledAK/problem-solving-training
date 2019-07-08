//https://codeforces.com/problemset/problem/400/A
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
 
        int n, k;
 
         n = reader.nextInt();
 
 
        for(int m = 0 ; m < n ; m ++)
        {
 
 
        String str;
        str=reader.next();
        int a[]=new int[12+1];
 
 
        a[12]=1;
 
        //check for case 1 and 6
        for(int i=0;i<12;i++){
            if(str.charAt(i)=='O')a[12]=0;
 
            if(str.charAt(i)=='X')a[1]=1;
        }
 
        //check for case 2 and 5
        int j=6;
        int left=1,right=1;
        a[6]=1;
 
 
        for(int i=0;i<12;i++) {
 
            if (i % 2 == 0) {
                if (str.charAt(i) == 'O') left = 0;
            } else {
                if (str.charAt(i) == 'O') right = 0;
            }
 
            if (left == 0 && right == 0) a[6] = 0;
 
            if (i < 6) {
                if (str.charAt(i) == 'X' && str.charAt(j) == 'X') a[2] = 1;
                j++;
            }
        }
 
        //check for case 3 and 4
        int middle=1;
        j=4;
        k=8;
        left=1;
        right=1;
        a[4]=1;
 
 
        for(int i=0;i<12;i++){
 
            if(i%3==0){
                if(str.charAt(i)=='O')left=0;
            }else if(i%3==1){
                if(str.charAt(i)=='O')middle=0;
            }else{
                if(str.charAt(i)=='O')right=0;
            }
 
            if(left==0 && right == 0 &&middle==0)a[4]=0;
 
 
            if(i<4) {
                if (str.charAt(i) == 'X' && str.charAt(j) == 'X' && str.charAt(k) == 'X') a[3] = 1;
                j++;
                k++;
            }
        }
 
        int c=0;
 
        for(int i = 0 ; i < a.length;i++){
            if(a[i]==1)
                c++;
        }
        out.print(c+" ");
        for(int i = 0 ; i < a.length;i++){
            if(a[i]==1)
                out.print(i+"x"+12/i+" ");
        }
            out.println();
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
