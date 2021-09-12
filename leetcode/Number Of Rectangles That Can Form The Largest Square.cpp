class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int k=0, maxLength=0, count=0;
        for(const auto& i:rectangles) {    
            k=min(i[0],i[1]);
            
            if(maxLength<k) {
                maxLength=k;
                count=1;
            }
            else if(maxLength==k) 
                ++count;
        }
        return count;
    }
};
