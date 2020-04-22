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
        vector<int> mins;
 
        for (int x = 0; x < n; x++) {
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int value = binaryMatrix.get(x, mid);
                if (value == 1) {
                    if ((mid == 0) || (mid > 0 && binaryMatrix.get(x, mid - 1)) == 0) {
                        mins.push_back(mid);
                        break;
                    }
                    high = mid - 1;
                } else if (value == 0) {
                    low = mid + 1;
                }
            }
        }
        return mins.empty() ? -1 : *min_element(mins.begin(), mins.end());
    }
};
