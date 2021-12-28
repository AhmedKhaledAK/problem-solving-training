class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = (int) list1.size();
        int n2 = (int) list2.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n1; i++) {
            mp[list1[i]] = i;
        }
        vector<string> res;
        int minSum = INT_MAX, sum = 0;
        for (int j = 0; j < n2; j++) {
            if (mp.find(list2[j]) != mp.end()) {
                sum = j + mp[list2[j]];
                if (sum < minSum) {
                    vector<string> tmp;
                    res = tmp;
                    res.push_back(list2[j]);
                    minSum = sum;
                } else if (sum == minSum) {
                    res.push_back(list2[j]);
                }
            }
        }
        return res;
    }
};
