int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int na = (int) A.size(), ans = 0;
    if (na == 1){
        return 0;
    }
    for (int i = 0; i < na - 1; i++) {
        int dist = max(abs(A[i] - A[i + 1]), abs(B[i] - B[i + 1]));
        ans += dist;
    }
    return ans;
}

