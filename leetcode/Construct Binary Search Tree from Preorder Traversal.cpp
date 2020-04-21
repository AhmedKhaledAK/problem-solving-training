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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode *root = new struct TreeNode(preorder[0]);
        for (int i = 1; i < n; i++) {
            insert(root, preorder[i]);
        }
        return root;
    }
    
    TreeNode* insert(TreeNode* node, int k) {
        if (node == NULL) {
            return new struct TreeNode(k);
        }
        if (node->val > k) {
            node->left = insert(node->left, k);
        } else {
            node->right = insert(node->right, k);
        }
        return node;
    }
};
