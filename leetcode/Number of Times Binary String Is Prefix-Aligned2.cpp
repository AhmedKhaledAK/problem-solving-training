class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        set<int> st;
        int n = flips.size();
        int count = 0;
        for (int flip : flips) {
            st.insert(flip);
            if (st.size() == *st.rbegin()) {
                count++;
            }
        }
        return count;
    }
};
