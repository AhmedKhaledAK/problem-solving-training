class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        string ans = "";
        for(char c : s) {
            freq[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }
        pair<int, char> prev{-1, '#'};
        while(!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            ans += curr.second;
            if(prev.first > 0) pq.push(prev);
            curr.first--;
            prev = curr;
        }
        if (ans.length() == s.length()) return ans;
        return "";
    }
};