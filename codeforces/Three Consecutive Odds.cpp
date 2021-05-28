class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt_odds = 0;
        for (int e : arr) {
            if (e % 2 != 0) {
                cnt_odds++;
                if (cnt_odds == 3) {
                    return true;
                }
            } else {
                cnt_odds = 0;
            }
        }
        return false;
    }
};
