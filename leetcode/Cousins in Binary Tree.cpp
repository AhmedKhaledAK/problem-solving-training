/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int p1 = -1, p2 = -1, d1 = -1, d2 = -1;
        return traverse(root, x, y, root->val, p1, p2, -1, d1, d2);
    }
    
    bool traverse(TreeNode* node, int x, int y, int p, int& p1, int& p2, int d, int& d1, int& d2) {
        if (node == NULL) {
            return false;
        }
        d++;
        if (node->val == x) {
            d1 = d;
            p1 = p;
        } else if (node->val == y) {
            d2 = d;
            p2 = p;
        }
        if (d1 && d2 != -1) {
            if (d1 == d2 && p1 != p2) {
                return true;
            }
        }
        bool left = traverse(node->left, x, y, node->val, p1, p2, d, d1, d2);
        bool right = traverse(node->right, x, y, node->val, p1, p2, d, d1, d2);
        return left || right; 
    }
};
