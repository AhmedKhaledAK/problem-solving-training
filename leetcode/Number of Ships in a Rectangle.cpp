/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        if (topRight[0] - bottomLeft[0] == 0 && topRight[1] - bottomLeft[1] == 0) { // one point 
            return 1;
        }
        if (topRight[0] - bottomLeft[0] >= topRight[1] - bottomLeft[1]) {
            vector<int> top_right{(topRight[0] + bottomLeft[0]) / 2, topRight[1]};
            vector<int> bot_left{(topRight[0] + bottomLeft[0]) / 2 + 1, bottomLeft[1]}; 
            return countShips(sea, top_right, bottomLeft) + countShips(sea, topRight, bot_left);
        } 
        vector<int> top_right{topRight[0], (topRight[1] + bottomLeft[1]) / 2};
        vector<int> bot_left{bottomLeft[0], (topRight[1] + bottomLeft[1]) / 2 + 1}; 
        return countShips(sea, top_right, bottomLeft) + countShips(sea, topRight, bot_left);
    }
};
