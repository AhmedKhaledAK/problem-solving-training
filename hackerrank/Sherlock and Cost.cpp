// Complete the cost function below.
int cost(vector<int> B) {
    int dp[B.size()][2];

    memset(dp, 0, sizeof(dp));

    for(int i =0; i < B.size()-1; i++){
        dp[i+1][0]=max(dp[i][0], dp[i][1]+abs(B[i]-1));
        dp[i+1][1]=max(dp[i][0]+abs(B[i+1]-1), dp[i][1]+abs(B[i]-B[i+1]));
    }
    return max(dp[B.size()-1][0], dp[B.size()-1][1]);
}

