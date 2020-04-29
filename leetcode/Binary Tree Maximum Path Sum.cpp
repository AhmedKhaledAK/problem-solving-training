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
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        traverse(root, mx);
        return mx;
    }
    
    int traverse (TreeNode* node, int& mx) {
        if (node == NULL) {
            return 0;
        }
        int leftsum = traverse(node->left, mx);
        int rightsum = traverse(node->right, mx);
        mx = max({mx, leftsum + rightsum + node->val, node->val, leftsum + node->val, rightsum + node->val});
        return max({leftsum + node->val, rightsum + node->val, node->val});
    }
};
