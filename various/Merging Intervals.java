
/**

You have two sorted arrays, where each element is an interval. Now, merge the two array, overlapping intervals can be merged as a single one.

I/P :
List 1 [1,2] , [3,9]
List 2 [4,5], [8, 10], [11,12]

O/P [1,2], [3,10], [11,12]


*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        //InputStreamReader isr = new InputStreamReader(System.in);
        //BufferedReader br = new BufferedReader(isr);



        List<int []> res = mergeInterval(new int[][]{{1,2},{3,9}}, new int[][]{{4,5},{8,10},{11,12}});

        for (int[] re : res) {
            out.print("[");
            for (int j = 0; j < 1; j++) {
                out.print(re[j] + ",");
            }
            out.print(re[1]);
            out.println("]");
        }

        out.flush();
    }


    public static List<int[]> mergeInterval(int[][] l1, int[][] l2) {
        int i =0, j =0;
        List<int []> result = new LinkedList<>();
        while(i < l1.length && j < l2.length){
            if(l2[j][1] > l1[i][0]){
                mergeWithResult(result, l1[i][0], l1[i][1]);
                i++;
            } else if(l1[i][1] > l2[j][0]){
                mergeWithResult(result, l2[j][0], l2[j][1]);
                j++;
            }
        }
        while (i < l1.length){
            mergeWithResult(result, l1[i][0], l1[i][1]);
            i++;
        }

        while (j < l2.length){
            mergeWithResult(result, l2[j][0], l2[j][1]);
            j++;
        }
        return result;
    }

    private static void mergeWithResult(List<int[]> result, int e1, int e2) {
        if(result.isEmpty())
            result.add(new int[]{e1,e2});
        else {
            int [] ar = result.get(result.size()-1);
            if(ar[1] < e1){
                result.add(new int[]{e1,e2});
            } else {
                int[] newAr = new int[2];
                newAr[0] = Integer.min(ar[0], e1);
                newAr[1] = Integer.max(ar[1], e2);
                result.remove(result.size() - 1);
                result.add(newAr);
            }
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
}
