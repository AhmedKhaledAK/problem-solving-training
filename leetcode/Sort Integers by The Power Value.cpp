class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> dp(1000001, -1);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for (int i = lo; i <= hi; i++)
        {
            int val = getPower(i, dp);
            pq.push(make_pair(val, i));
        }
        while (--k)
        {
            pq.pop();
        }
        return pq.top().second;
    }
    
    int getPower(int i, vector<int>& dp)
    {
        if (dp[i] != -1)
        {
            return dp[i];
        }
        if (i == 1)
        {
            return 0;
        }
        int cnt = 0;
        if (i & 1)
        {
            cnt = 1 + getPower(3 * i + 1, dp);
        }
        else
        {
            cnt = 1 + getPower(i / 2, dp);
        }
        return dp[i] = cnt;
    }
};
