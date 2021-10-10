class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if (sequence.size() < word.size()) { return 0; }
        int ans = 0;
        string temp = word;
        while (word.size() <= sequence.size()) {
            if (sequence.find(word) == string::npos) { 
                break;
            }
            ans++;
            word += temp;
        }
        return ans;
    }
};
