
/*

Find whether string S is periodic.
Periodic indicates S = nP.
e.g.
S = "ababab", then n = 3, and P = "ab"
S = "xxxxxx", then n = 1, and P = "x"
S = "aabbaaabba", then n = 2, and P = "aabba"
follow up:
Given string S, find out the P (repetitive pattern) of S.

*/


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        //InputStreamReader isr = new InputStreamReader(System.in);
        //BufferedReader br = new BufferedReader(isr);


        String s = "aabbaaabbaaabba";
        ArrayList<Character> al = new ArrayList<>();
        int n = 0;

        for(int i =0; i < s.length()/2; i++){
            al.add(s.charAt(i));
            int j = i+1;
            for(; j < s.length(); j+=i+1){
                int h = j;
                int x= 0;
                for(; x < al.size(); x++){
                    if(s.charAt(h) != al.get(x)){
                        break;
                    } else {
                        h++;
                    }
                }
                if(x != al.size())
                    break;
                n++;
            }
            if(j >= s.length()){
                out.println("P: " + al);
                break;
            }
        }
        out.print("n: " + n);
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
