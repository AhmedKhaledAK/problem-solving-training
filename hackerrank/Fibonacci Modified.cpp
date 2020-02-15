import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.math.BigInteger;

public class Solution {

    // Complete the fibonacciModified function below.
    // Changed the return type to BigInteger and edited it in main method too.
    static BigInteger fibonacciModified(int t1, int t2, int n) {

        BigInteger [] dp = new BigInteger[n];

   

        dp[0] = BigInteger.valueOf(t1);
        dp[1] = BigInteger.valueOf(t2);

        for(int i =2; i < n; i++){

            dp[i] = (dp[i-1].pow(2)).add(dp[i-2]);
        }

        return dp[n-1];

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] t1T2n = scanner.nextLine().split(" ");

        int t1 = Integer.parseInt(t1T2n[0]);

        int t2 = Integer.parseInt(t1T2n[1]);

        int n = Integer.parseInt(t1T2n[2]);

        BigInteger result = fibonacciModified(t1, t2, n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

