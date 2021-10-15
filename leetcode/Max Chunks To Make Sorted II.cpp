class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sz = arr.size();
        vector<int> maxValues(sz, 0);
        vector<int> minValues(sz, 0);
        int maxValue = INT_MIN;
        for (int i = 0; i < sz; i++) {
            maxValue = max(maxValue, arr[i]);
            maxValues[i] = maxValue;
        }
        int minValue = INT_MAX;
        for (int i = sz - 1; i >= 0; i--) {
            minValue = min(minValue, arr[i]);
            minValues[i] = minValue;
        }
        int chunks = 0;
        for (int i = 0; i < sz - 1; i++) {
            if (maxValues[i] <= minValues[i + 1]) {
                chunks++;
            }
        }
        return ++chunks;
    }
};
