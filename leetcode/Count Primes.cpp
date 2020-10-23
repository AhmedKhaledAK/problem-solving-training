class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primeTable(n);
        fill(primeTable.begin(), primeTable.end(), 1);
        int cnt = 0;
        for (int p = 2; p*p < n; p++) {
            if (primeTable[p]) {
                for (int i = p*p; i < n; i += p) {
                    primeTable[i] = false;
                }
            }
        }
        
        for (int i = 2; i < n; i++) {
            if (primeTable[i]) cnt++;
        }
        
        return cnt;
    }
};
