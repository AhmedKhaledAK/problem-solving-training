class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = (int) matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = (int) matrix[0].size();
        vector<int> dp(m);
        int mx = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    dp[j] = 0;
                } else {
                    dp[j] += matrix[i][j] - '0';
                }
            }
            int rect = largestRectangleArea(dp);
            mx = max(rect, mx);
        }
        return mx;
    }
    
    int largestRectangleArea(vector<int> heights) {
        int n = (int) heights.size();
        stack<int> st;
        int i = 0, max_area = 0, area;
        while (i < n) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i);
                i++;
            } else {
                int t = st.top();
                st.pop();
                area = heights[t] * (st.empty() ? i : i - st.top() - 1);
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        
        while (!st.empty()) {
            int t = st.top();
            st.pop();
            area = heights[t] * (st.empty() ? i : i - st.top() - 1);
            if (area > max_area) {
                max_area = area;
            }
        }
        return max_area;
    }
};
