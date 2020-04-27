int Solution::maxSubArray(const vector<int> &A) {
    int n = (int) A.size();
    int dp[n];
    dp[0] = A[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(0, dp[i - 1]) + A[i];
    }
    return *max_element(dp, dp+n);
}

