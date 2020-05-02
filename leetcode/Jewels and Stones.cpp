class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewel;
        for (char c : J) {
            jewel.insert(c);
        }
        int ans = 0;
        for (char c : S) {
            if (jewel.find(c) != jewel.end()) {
                ans++;
            }
        }
        return ans;
    }
};
