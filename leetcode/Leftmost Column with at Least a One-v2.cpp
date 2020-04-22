/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0], m = binaryMatrix.dimensions()[1];
        int p = binaryMatrix.get(0, m - 1);
        
        int x = 0, c = m - 1, res = INT_MAX;
        
        while (x < n) {
            cout << x << " " << c << " " << res << endl;
            int b = false;
            while (p == 1 && c >= 0) {
                if (c == 0) return 0;
                c--;
                p = binaryMatrix.get(x, c);
                b = true;
                cout << "here " << c << endl;
            }
            if (b) {
                res = min(res, c + 1);
            }
            b = false;
            while (p == 0 && x < n-1) {
                x++;
                p = binaryMatrix.get(x, c);
                b = true;
            }
            if (!b) {
                x++;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
