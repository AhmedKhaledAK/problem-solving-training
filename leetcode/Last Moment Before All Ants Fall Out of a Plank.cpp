class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;
        for (auto ant : left) {
            time = max(time, ant);
        }
        for (auto ant : right) {
            time = max(time, n - ant);
        }
        return time;
    }
};
