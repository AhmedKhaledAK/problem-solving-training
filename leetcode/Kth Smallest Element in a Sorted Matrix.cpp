class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int H = matrix.size();
        int W = matrix[0].size();
        priority_queue<int> pq;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};
