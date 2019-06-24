//https://codeforces.com/problemset/problem/433/B

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main (String [] args)
    {
        Scanner sc= new Scanner(System.in);
        int n= sc.nextInt();
        int m;
        Long v[] = new Long[n]; //unsorted
        Long u[]= new Long[n];  // to be sorted

        for (int i=0;i<n ;i++)
        {
            v[i]=sc.nextLong();
            u[i]=v[i];
        }

        Arrays.sort(u);

        Long addedV[]= new Long[n];  // to be sorted
        Long addedU[]= new Long[n];  // to be sorted
        addedU=computeSum(u);
        addedV=computeSum(v);

        m=sc.nextInt();
        for(int i=0;i<m;i++)
        {
            int type=sc.nextInt();
            int l=sc.nextInt();
            int r=sc.nextInt();
            if(type==1)
            {
                System.out.println(answerKuri(l-1,r-1,addedV));
            }else if(type==2)
            {
                System.out.println(answerKuri(l-1,r-1,addedU));

            }

        }

    }

    public static Long [] computeSum(Long []arr)
    {
        long s=arr[0];
        Long sum[]= new Long[arr.length];  // to be sorted
        sum[0]=s;
        for(int i=1;i<arr.length;i++)
        {
            s+=arr[i];
            sum[i]=s;
        }

        return sum;

    }

    public static long answerKuri(int l , int r, Long []arr)
    {
        long ans=0;
        long upper= arr[r];
        long lower;

        if(l>0)
        {
            lower=arr[l-1];
        }else {
            lower=0;
        }
        ans=upper-lower;
        return ans;
    }

}
