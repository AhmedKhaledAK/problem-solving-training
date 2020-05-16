class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = (int) A.size();
        int mx = *max_element(A.begin(), A.end());
        if (mx < 0) {
            return mx;
        }
        int normal_sum = kadane(A, n);
        int circular_sum = 0;
        for (int i = 0; i < n; i++) {
            circular_sum += A[i];
            A[i] = -A[i];
        }
        circular_sum += kadane(A, n);
        return max(normal_sum, circular_sum);
    }
    
    int kadane (vector<int>& A, int n) {
        int ans, sum;
        ans = sum = A[0];
        for (int i = 1; i < n; i++) {
            ans = max(A[i], ans + A[i]);
            sum = max(ans, sum);
        }
        return sum;
    }
    
};
