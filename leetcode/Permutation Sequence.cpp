class Solution {
public:
    string getPermutation(int n, int k) {
        int cnt = 0;
        string s = "";
        for (int i = 1; i <= n; i++) {
            s += to_string(i);
        }
        do {
            cnt++;
            if (cnt == k) {
                break;
            }
        } while (next_permutation(s.begin(), s.end()));
        return s;
    }
};
