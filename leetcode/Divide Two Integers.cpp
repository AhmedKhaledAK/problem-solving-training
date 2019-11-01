class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        
        bool isneg = false;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) isneg = true;
        
        long long lup = abs((long long) dividend);
        long long ldown = abs((long long) divisor);
        
        int cnt =0;
        
        while(lup >= ldown){
            int shift = 0;
            while(lup >= (ldown << shift)){
                shift++;
            }
            cnt += (1 << (shift-1));
            lup -= (ldown << (shift-1));
        }
        
        long long lcnt = abs((long long) cnt);
        if(lcnt > INT_MAX && !isneg) cnt = INT_MAX;
        
        if(isneg && cnt > 0)
            cnt = -cnt;
        
       
        
        return cnt;
    }
};
