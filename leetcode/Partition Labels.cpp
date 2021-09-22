class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }
        vector<int> res;
        int start, end;
        start = end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (end == i)
            {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
