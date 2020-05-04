class Solution {
public:
    int findComplement(int num) {
        int ans = 0, idx = -1;
        for (int bit = 30; bit >= 0; bit--) {
            if ((num & (1 << bit)) != 0) {
                idx = bit;
                break;
            }
        }
        if (idx == -1) {
            return 0xffffffff;
        }
        for (int bit = idx; bit >= 0; bit--) {
            ans |= (num & (1 << bit));
            ans ^= (1 << bit);
        }
        return ans;
    }
};
