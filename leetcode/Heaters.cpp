class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int sz = heaters.size();
        int ans = max(heaters[0] - houses[0], 0);
        int left = -1, right = -1;
        for (int i = 0; i < sz - 1; i++)
        {
            left = upper_bound(houses.begin(), houses.end(), heaters[i]) - houses.begin();
            right = upper_bound(houses.begin(), houses.end(), heaters[i + 1]) - houses.begin();
            for (int j = left; j < right; j++)
            {
                ans = max(ans, min(abs(houses[j] - heaters[i]), abs(houses[j] - heaters[i + 1])));
            }
        }
        if (right == -1)
            right = upper_bound(houses.begin(), houses.end(), heaters[sz - 1]) - houses.begin();
        if (right < houses.size())
        {
            ans = max(ans, houses.back() - heaters.back());
        }
        return ans;
    }
};
