class Solution {
public:
    int climbStairs(int n) {
        int before = 1, bbefore = 1;
        
        for (int i = 2; i <= n; i++) {
            int ans = before + bbefore;
            bbefore = before; 
            before = ans;
        }
        return before;
    }
};
