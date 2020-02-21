long long mod = 1000000000+7;


/**
States: - arrays that end in x
        - arrays that do not end in x
*/

// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.

    long long endx[n], noendx[n];

    endx[0] = x == 1 ? 1 : 0;
    noendx[0] = x == 1 ? 0 : 1;

    for(int i =1; i < n; i++){
        endx[i] = noendx[i-1] % mod;
        noendx[i] = (endx[i-1] * (k-1) + noendx[i-1] * (k-2)) % mod;
    }

    return endx[n-1];

}
