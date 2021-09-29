class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sz = (int) code.size();
        bool rev = false;
        vector<int> res;
        if (k == 0)
        {
            res.resize(sz, 0);
            return res;
        }
        if (k < 0){
            reverse(code.begin(), code.end());
            rev = true;
        }
        for (int i = 0; i < sz; i++)
        {
            int j = i + 1, steps = 0, sum = 0;
            while (steps < abs(k))
            {
                sum += code[j % sz];
                j++;
                steps++;
            }
            res.push_back(sum);
        }
        if (rev)
            reverse(res.begin(), res.end());
        return res;
    }
};
