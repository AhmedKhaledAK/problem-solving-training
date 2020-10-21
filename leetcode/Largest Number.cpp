class Solution {
    
    
    static bool cmp(const string & s1, const string & s2) {
        string o1 = s1 + s2;
        string o2 = s2 + s1;
        return o1 > o2;
    }
    
    
public:
    string largestNumber(vector<int>& nums) {
        vector<string> startNum;
        for (int num : nums) {
            startNum.push_back(to_string(num));
        }
    
        
        sort(startNum.begin(), startNum.end(), cmp);
        
        if (startNum[0] == "0") {
            return "0";
        }
        
        string ans = "";
        
        for (string s : startNum) {
            ans += s;
        }
        
        return ans;
    }
};
