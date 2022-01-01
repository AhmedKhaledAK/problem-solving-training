class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int count, sum, seqSum;
        count = sum = seqSum = 0;
        int n = (int) flips.size();
        for (int i = 0; i < n; i++) {
            sum += flips[i];
            seqSum += i + 1;
            if (sum == seqSum) {
                count++;
            }
        }
        return count;
    }
};
