class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<bool> oddStarts(n), evenStarts(n);
        oddStarts[n - 1] = evenStarts[n - 1] = true;
        int cnt = 1;
        for (int i = n - 2; i >= 0; i--) {
            int o = canOddJump(i, A);
            int e = canEvenJump(i, A);
            if (o != -1 && evenStarts[o]) {
                cnt++;
                oddStarts[i] = true;
            }
            evenStarts[i] = (e != -1 && oddStarts[e]);
        }
        return cnt;
    }
    
    int canOddJump(int i, vector<int>& A) {
        int mx = INT_MAX;
        int idx = -1;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] >= A[i] && A[j] < mx) {
                mx = A[j];
                idx = j;
            }
        }
        return idx;
    }
    
    int canEvenJump(int i, vector<int>& A) {
        int mn = INT_MIN;
        int idx = -1;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] <= A[i] && A[j] > mn) {
                mn = A[j];
                idx = j;
            }
        }
        return idx;
    }
};
