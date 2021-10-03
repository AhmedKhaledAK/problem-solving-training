class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = (int) hand.size();
        if (n % groupSize != 0)
            return false;
        
        map<int, int> freq;
        for (int num : hand) {
            freq[num]++;
        }
        while(freq.size() != 0) {
            int curr = freq.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                auto currI = freq.find(curr + i);
                if (currI == freq.end()) {
                    return false;
                }
                if (--freq[curr + i] == 0) {
                    freq.erase(currI);
                }
            }
        }
        return true;
    }
};
