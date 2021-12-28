class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int H = (int) groups.size();
        int n = (int) nums.size();
        int ptr = 0;
        for (int i = 0; i < H; i++) {
            vector<int> row = groups[i];
            int sz = (int) row.size();
            while (ptr < n && nums[ptr] != row[0]) {
                ptr++;
            }
            int temp = ptr + 1;
            for (int j = 0; j < sz; j++) {
                if (ptr == n) {
                    return false;
                }
                if (nums[ptr] != row[j]) {
                    i--;
                    ptr = temp;
                    break;
                }
                ptr++;
            }
        }
        return true;
    }
};
