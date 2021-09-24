class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans = 0;
        for (int n : nums)
        {
            freq[n]++;
        }
        
        for (auto it : freq)
        {
            int occ = it.second;
            ans = ans + (occ * (occ - 1) / 2);
        }
        return ans;
    }
};
