#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i =0,j=height.size()-1;
        
        while(i < j){
            ans = max(ans, min(height[i], height[j]) * (j-i));
            if(height[i] < height[j])
                i++;
            else 
                j--;
        }
        return ans;
    }
};
