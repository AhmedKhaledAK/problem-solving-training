class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> fnd;
        while (n != 1) {
            n = sumdigits(n,0);
            if (fnd[n]) return false;
            fnd[n] = true;
        }
        return true;
    }
    
    int sumdigits(int n, int sum){
        if (n==0) return sum;
        int r = n % 10;
        sum += r*r;
        return sumdigits(n / 10, sum);
    }
};
