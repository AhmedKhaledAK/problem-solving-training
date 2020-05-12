class Solution {
private:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        bt(image, sr, sc, image[sr][sc]);
        for (int i = 0; i < (int) image.size(); i++) {
            for (int j = 0; j < (int) image[0].size(); j++) {
                if (image[i][j] == '.') {
                    image[i][j] = newColor;
                }
            }
        }
        return image;
    }
    
    void bt (vector<vector<int>>& image, int i, int j, int color) {
        image[i][j] = '.';
        for (int k = 0; k < 4; k++) {
            int nwi = i + row[k];
            int nwj = j + col[k];
            if (isvalid(nwi, nwj, image.size(), image[0].size())) {
                if (image[nwi][nwj] == color) {
                    bt(image, nwi, nwj, color);
                }
            }
        }
    }
    
    bool isvalid (int i, int j, int r, int c) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
};
