class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOnes, maxZeros, cntOnes, cntZeros;
        maxOnes = maxZeros = cntOnes = cntZeros = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                maxOnes = max(maxOnes, cntOnes);
                cntOnes = 0;
                
                cntZeros++;
            } else {
                maxZeros = max(maxZeros, cntZeros);
                cntZeros = 0;
                
                cntOnes++;
            }
        }
        maxOnes = max(maxOnes, cntOnes);
        maxZeros = max(maxZeros, cntZeros);
        return maxOnes > maxZeros;
    }
};