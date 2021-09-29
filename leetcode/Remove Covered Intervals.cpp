class Solution {
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[0] < b[0]) 
            return true;
        else if (a[0] == b[0])
            return a[1] > b[1];
        return false;
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (vector<int> v : intervals) 
        {
            merge(v, merged);
        }
        return merged.size();
    }
    
    void merge(vector<int>& v, vector<vector<int>>& merged)
    {
        vector<int> last = merged.back();
        if (last[1] < v[1])
        {
            merged.push_back(v);
        }
    }
};
