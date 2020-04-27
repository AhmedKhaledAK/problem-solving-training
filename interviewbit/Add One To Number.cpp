vector<int> Solution::plusOne(vector<int> &A) {
    int n = (int) A.size();
    vector<int> ans;
    int rem = 0;
    for (int i = n - 1; i >= 0; i--) {
        int plus = 0;
        if (i == n - 1) {
            plus = A[i] + 1;
        } else {
            plus = A[i] + rem;
        }
        ans.push_back(plus % 10);
        rem = plus / 10;
    }
    if (rem != 0) {
        ans.push_back(rem);
    }
    while (ans.back() == 0) {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

