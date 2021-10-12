class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA, sumB;
        sumA = sumB = 0;
        unordered_set<int> setB;
        for (int n : aliceSizes) sumA += n;
        for (int n : bobSizes) {
            sumB += n;
            setB.insert(n);
        };
        int delta = (sumB - sumA) / 2;
        for (int num : aliceSizes) {
            if (setB.count(num + delta) == 1) {
                return {num, num + delta};
            }
        }
        // unreachable because it is guaranteed there is an answer
        return {};
    }
};
