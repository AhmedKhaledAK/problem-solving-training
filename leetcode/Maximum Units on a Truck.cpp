class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] >= b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        for (auto v : boxTypes)
        {
            if (truckSize == 0)
            {
                break;
            }
            int boxes = truckSize > v[0] ? v[0] : truckSize;
            ans += (boxes * v[1]);
            truckSize -= boxes;
        }
        return ans;
    }
};
