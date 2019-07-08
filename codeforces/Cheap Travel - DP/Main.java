//https://codeforces.com/problemset/problem/466/A

import java.util.Scanner;

public class Main {
    public static void main (String [] args)
    {
        Scanner sc=new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();



        int ans=(n/m)*b;


        if ( (n%m)*a > b )
        {
            ans+=b;
        }else
        {
            ans+=(n%m)*a;
        }

        int ansN=a*n;
        int ansM=(n/m + 1 ) * b;
        int temp=Math.min(ans,ansM);
        System.out.println( Math.min(temp,ansN) );

    }

}
