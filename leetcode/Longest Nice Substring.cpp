class Solution {
public:
    string longestNiceSubstring(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            int diff = s[i] > 'Z' ? -32 : 32;
            if (s.find(s[i] + diff) != s.npos)
            {
                continue;
            }
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));
            return left.size() >= right.size() ? left : right;
        }
        return s;
    }
};
