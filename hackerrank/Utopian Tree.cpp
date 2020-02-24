int utopianTree(int n) {

    int dp[n+1];
    dp[0]=1;

    for(int i =1; i <= n; i++){
        dp[i] = i % 2 == 0 ? dp[i-1]+1 : dp[i-1]*2;
    }
    return dp[n];
}

