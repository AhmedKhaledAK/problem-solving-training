class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> A = count(n);
        for (int i = 0; i < 31; i++) {
            if (A == count(1 << i)) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> count(int n) {
        vector<int> vec(10);
        while (n > 0) {
            vec[n % 10]++;
            n /= 10;
        }
        return vec;
    }
};
