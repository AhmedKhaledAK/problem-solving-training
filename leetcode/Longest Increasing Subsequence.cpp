class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int T [nums.size()];
        for(int i = 0; i<nums.size(); i++){
            T[i]=1;
        }
        int mx = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && T[i] < T[j]+1){
                    T[i] = T[j]+1;
                    mx = max(mx, T[i]);
                }
            }
        }
        return mx;
    }
};
