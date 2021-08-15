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
    int ans;
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        maxPath(root);
        return ans;
    }
    
    int maxPath(TreeNode* node) {
        if (!node) return 0;
        int left = maxPath(node->left);
        int right = maxPath(node->right);
        int arrowLeft, arrowRight;
        arrowLeft = arrowRight = 0;
        if (node->left && node->left->val == node->val) {
            arrowLeft += left + 1;
        }
        if (node->right && node->right->val == node->val) {
            arrowRight += right + 1;
        }
        ans = max(ans, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
};
