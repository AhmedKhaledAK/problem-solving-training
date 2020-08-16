class Solution {
    
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[0] <= v2[0];
    }
    
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> endTimes;
        sort(intervals.begin(), intervals.end(), cmp);
        endTimes.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= endTimes.top()) {
                endTimes.pop();
            }
            endTimes.push(intervals[i][1]);
        }
        return endTimes.size();
    }
};
