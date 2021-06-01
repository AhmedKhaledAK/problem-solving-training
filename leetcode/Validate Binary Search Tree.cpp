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
    bool isValidBST(TreeNode* root) {
        long long int min_value = LONG_MIN;
        long long int max_value = LONG_MAX;
        return validateBST(root, min_value, max_value);
    }
    
    bool validateBST(TreeNode* node, long long int min_value, long long int max_value) {
        if (!node) {
            return true;
        }
        if (node->val < min_value || node->val > max_value) {
            return false;
        }
        return (validateBST(node->left, min_value, (long long int) node->val - 1) && 
               validateBST(node->right, (long long int) node->val + 1, max_value));
    }
};