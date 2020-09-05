class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev = -1, future = 0;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                prev = i;
            } else {
                while (future < n && seats[future] == 0 || future < i) {
                    future++;
                }
                int left = prev == -1 ? n : i - prev;
                int right = future == n ? n : future - i;
                ans = max(ans, min(left, right));
            }
        }
        
        
        return ans;
    }
};
