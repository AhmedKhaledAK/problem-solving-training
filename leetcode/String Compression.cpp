class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int start = 0, i = 1;
        for (; i < chars.size(); i++) {
            if (chars[i] != chars[i - 1]) {
                s += chars[i - 1];
                if (i - start != 1) {
                    s += to_string(i - start);
                }
                start = i;
            }
        }
        s += chars[chars.size() - 1];
        if (i - start != 1) {
            s += to_string(i - start);
        }
        cout << s << endl;
        for (int i = 0; i < s.length(); i++) {
            chars[i] = s[i];
        }
        return s.length();
    }
};
