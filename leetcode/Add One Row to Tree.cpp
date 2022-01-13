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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        insert(root, val, 1, depth);
        return root;
    }
    
    void insert(TreeNode* node, int val, int currDepth, int depth) {
        if (!node) {
            return;
        }
        if (currDepth == depth - 1) {
            TreeNode* temp = node->left;
            node->left = new TreeNode(val);
            node->left->left = temp;
            temp = node->right;
            node->right = new TreeNode(val);
            node->right->right = temp;
        } else {
            insert(node->left, val, currDepth + 1, depth);
            insert(node->right, val, currDepth + 1, depth);
        }
    }
    
};
