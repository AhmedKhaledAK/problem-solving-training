#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt=0, sw=0, max=-1;
        map<char, bool> mp;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(mp[c] != true){
                cnt++;
                mp[c]=true;
                if(cnt>max)
                    max=cnt;
            }else {
                if(cnt>max)
                    max=cnt;
                while(sw != i){
                    cnt--;
                    int h = sw++;
                    if(s[h] != c){
                        mp[s[h]] = false;
                    }else {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return max > -1 ? max : cnt;
    }
};
