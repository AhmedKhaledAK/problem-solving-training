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
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, sum, 0);
    }
    
    bool helper(TreeNode* root, int sum, int acc) {
        if (root == NULL) {
            return false;
        }
        acc += root->val;
        if (acc == sum && !root->right && !root->left) {
            return true;
        }
        if (acc != sum && !root->right && !root->left) {
            return false;
        }
        return helper(root->left, sum, acc) || helper(root->right, sum, acc);
    }
};
