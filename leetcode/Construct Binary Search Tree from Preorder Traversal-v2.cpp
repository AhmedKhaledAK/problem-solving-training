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
        int id = 0;
        return insert(preorder, id, INT_MAX);
    }
    
    TreeNode* insert(vector<int>& preorder, int& id, int limit) {
        if (id == preorder.size() || preorder[id] > limit) {
            return NULL;
        }
        int value = preorder[id];
        TreeNode* node = new struct TreeNode(value);
        id++;
        node->left = insert(preorder, id, value);
        node->right = insert(preorder, id, limit);
        return node;
    }
};
