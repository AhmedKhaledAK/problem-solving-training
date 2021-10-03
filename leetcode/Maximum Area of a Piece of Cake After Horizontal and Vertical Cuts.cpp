class Solution {
    const int mod = 1e9+7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int H = horizontalCuts[0], W = verticalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); i++) {
            H = max(H, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        H = H = max(H, h - horizontalCuts.back());
        for (int i = 1; i < verticalCuts.size(); i++) {
            W = max(W, verticalCuts[i] - verticalCuts[i - 1]);
        }
        W = max(W, w - verticalCuts.back());
        long long int maxH = H, maxW = W;
        return (maxH * maxW) % mod;
    }
};
