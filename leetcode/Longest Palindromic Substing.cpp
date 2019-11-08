class Solution {
    bool T [1000][1000];
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        
        int lngst =1, strt =0;
        for(int i =0; i < s.length(); i++)
            T[i][i] = true;
        
         for(int i =0; i < s.length()-1; i++){
            if(s[i] == s[i+1]){
                lngst = 2;
                strt=i;
                T[i][i+1] = true;
            }
        }
        
        for(int i = 3; i <= s.length(); i++){
            for(int j = 0; j < s.length()-i+1; j++){
                int e = i+j-1;
                if(s[j] == s[e] && T[j+1][e-1]){
                    T[j][e] = true;
                    if(i>lngst){
                        lngst = i;
                        strt = j;
                    }
                }
            }
        }
        
        return s.substr(strt, lngst);
    }
};
