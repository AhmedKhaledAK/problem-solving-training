class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k >= arr.size()) {
            return *max_element(arr.begin(), arr.end());
        }
        bool isWinner = false;
        deque<int> dq(arr.begin(), arr.end());
        unordered_map<int, int> freq;
        int winner = -1;
        while (!isWinner) {
            if (dq[1] < dq[0]) {
                swap(dq[1], dq[0]);
            }
            int front = dq[0];
            dq.pop_front();
            dq.push_back(front);
            freq[dq[0]]++;
            if (freq[dq[0]] == k) {
                winner = dq[0];
                isWinner = true;
            }
        }
        return winner;
    }
};
