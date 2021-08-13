class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = (int) numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                int l = numbers[low];
                while(l == numbers[low]) {
                    low++;
                }
            } else {
                int h = numbers[high];
                while(h == numbers[high]) {
                    high--;
                }
            }
        }
        //unreachable
        return {};
    }
};