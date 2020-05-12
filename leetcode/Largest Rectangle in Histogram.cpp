class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
