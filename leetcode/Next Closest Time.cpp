class Solution {
public:
    string nextClosestTime(string time) {
        int curr = 60 * ((time[0] - '0') * 10 + (time[1] - '0'));
        curr += ((time[3] - '0') * 10 + (time[4] - '0'));
        
        unordered_set<int> allowed;
        
        for (int i = 0; i < time.length(); i++) {
            if (time[i] != ':') {
                allowed.insert(time[i] - '0');
            }
        }
        bool flag;
        while (true) {  // incrementing minute by minute
            flag = false;
            curr++;
            curr %= (24 * 60);
            
            vector<int> plusMinute {curr / 60 / 10, curr / 60 % 10, curr % 60 / 10, curr % 60 % 10};
            
            for (int m : plusMinute) {
                if (allowed.find(m) == allowed.end()) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                return to_string(curr / 60 / 10) + to_string(curr / 60 % 10) + ":" + to_string(curr % 60 / 10) + to_string(curr % 60 % 10);
            }
        }
    }
};
