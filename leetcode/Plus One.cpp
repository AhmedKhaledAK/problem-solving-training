class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int n = (int) A.size();
        vector<int> ans;
        int rem = 1, plus;
        for (int i = n - 1; i >= 0; i--) {
            plus = A[i] + rem;
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
};
