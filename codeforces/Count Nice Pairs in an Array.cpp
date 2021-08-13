class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int MOD = 1000000007;
        unordered_map<int, int> diff_freq;
        long long int ans = 0;
        for (int i = 0; i < (int) nums.size(); i++) {
            int rev = reverse_num(nums[i]);
            int diff = nums[i] - rev;
            if (diff_freq.find(diff) == diff_freq.end()) {
                diff_freq[diff] = 1;
            } else {
                ans += ((diff_freq[diff])%MOD);
                diff_freq[diff]++;
            }
        }
        return ans%MOD;
    }
    
    int reverse_num(int num) {
        int rev_num = 0;
        while (num > 0)
        {
            rev_num = rev_num*10 + num%10;
            num = num/10;
        }
        return rev_num;
    }
    
};


/*

nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])

map<diff, freq>

map = {<18, 2>, <0, 2>, }

*/