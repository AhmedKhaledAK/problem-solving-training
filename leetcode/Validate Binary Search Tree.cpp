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
        long long limit1, limit2;
        limit1 = limit2 = LONG_MAX;
        return helper(root, limit1, limit2);
    }
    bool helper(TreeNode* root, long long& limit1, long long& limit2) {
        if (root == NULL) {
            return true;
        }
        long long val = root->val;
        if (limit1 != LONG_MAX && val >= limit1) {
            return false;
        }
        if (limit2 != LONG_MAX && val <= limit2) {
            return false;
        }
        if (!helper(root->left, val, limit2)) {
            return false;
        }
        if (!helper(root->right, limit1, val)) {
            return false;
        }
        return true;
    }
};
