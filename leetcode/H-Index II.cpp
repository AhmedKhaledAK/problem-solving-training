class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = (int) citations.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] == n - mid) {
                return n - mid;
            }
            if (citations[mid] > n - mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return n - low;
    }
};