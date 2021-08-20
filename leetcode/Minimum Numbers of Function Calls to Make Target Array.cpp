class Solution {
public:
    int minOperations(vector<int>& nums) {
        int incOps = 0, multiOps = 0;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            int currNum = nums[i];
            int currMultiOps = 0;
            while (currNum > 0)
            {
                if (currNum % 2 != 0)
                {
                    incOps++;
                    currNum--;
                }
                else
                {
                    currMultiOps++;
                    currNum /= 2;
                }
            }
            multiOps = max(multiOps, currMultiOps);
        }
        return incOps + multiOps;
    }
};
