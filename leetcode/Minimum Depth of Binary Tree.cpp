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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = 1 + minDepth(root->left);
        int right = 1 + minDepth(root->right);
        if (left == 1 && right != 1) {
            return right;
        }
        if (left != 1 && right == 1) {
            return left;
        }
        return min(left, right);
    }
};
