class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int i = 0, count = 0;
        while (i <= 31) {
            if ( ((mask << i) & n) != 0) {
                count++;
            }
            i ++;
        }
        return count;
    }
};
