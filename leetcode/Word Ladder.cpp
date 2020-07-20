class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = (int) wordList.size();
        
        if (n == 0) {
            return 0;
        }
        
        unordered_set<string> S(wordList.begin(), wordList.end());
        
        if (S.find(endWord) == S.end()) {
            return 0;
        }
        
        queue<string> Q;
        Q.push(beginWord);
        
        int ans = 0;
        
        while (!Q.empty()) {
            ans++;
            int len = Q.size();
            for (int i = 0; i < len; i++) {
                string w = Q.front();
                Q.pop();
                
                for (int j = 0; j < w.length(); j++) {
                    char org_char = w[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        w[j] = c;
                        if (w == endWord) {
                            return ++ans;
                        }
                        if (S.find(w) == S.end()) {
                            continue;
                        }
                        S.erase(w);
                        Q.push(w);
                    }
                    w[j] = org_char;
                }
            }
        }
        return 0;
    }
};
