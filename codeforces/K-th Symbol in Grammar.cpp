class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1) {
            return 0;
        }
        int row_mid = pow(2,n-1)/2;
        if (k <= row_mid) {
            return kthGrammar(n - 1, k);
        } else {
            return !kthGrammar(n - 1, k - row_mid);
        }
    }
};

/*

3rd: 0 1 1 0 
4th: 0110 1001
5th: 01101001 10010110

*/
