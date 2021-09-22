class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++)
        {
            if (selfDivide(i)) res.push_back(i);
        }
        return res;
    }
    
    bool selfDivide(int num)
    {
        int hold = num;
        while(hold)
        {
            int d = hold % 10;
            if (d == 0 || num % d != 0) return false;
            hold = hold / 10;
        }
        return true;
    }
};
