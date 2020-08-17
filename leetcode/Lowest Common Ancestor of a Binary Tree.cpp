/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    TreeNode *anc;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return anc;
    }
    bool solve(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (!node) {
            return false;
        }
        
        int left = solve(node->left, p, q) ? 1 : 0;
        int right = solve(node->right, p, q) ? 1 : 0;
        int mid = node->val == p->val || node->val == q->val ? 1 : 0;
        
        if (mid + left + right >= 2) {
            anc = node;
        }
        
        return mid + left + right > 0;
    }
};
