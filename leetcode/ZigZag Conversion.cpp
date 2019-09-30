#include <vector>

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> ar(numRows);
        int cnt=0;
        bool isDown=false;
        
        for(int j=0; j < s.length(); j++){
            ar[cnt] += s[j];
            if(cnt == 0) isDown = true;
            else if(cnt == numRows - 1) isDown = false;
            cnt += isDown ? 1 : -1;
        }
        
        string sol;
        for(int i = 0; i < numRows; i++){
            for(int j =0; j < ar[i].length(); j++){
                sol+=ar[i][j];
            }
        }
        return sol;
    }
};
