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
    bool ok = true;
public:
    bool isBalanced(TreeNode* root) {
        depth(root);
        return ok;
    }
    
    int depth(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left = 1 + depth(node->left);
        int right = 1 + depth(node->right);
        if (abs(left - right) > 1) {
            ok = false;
        }
        return max(left, right);
    }
};
