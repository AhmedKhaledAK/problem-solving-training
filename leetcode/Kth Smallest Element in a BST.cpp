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
    int element;
public:
    int kthSmallest(TreeNode* root, int k) {
        int kk = 0;
        getKth(root, k, kk);
        return element;
    }
    
    void getKth(TreeNode* node, int k, int& kk) {
        if (!node) return;
        getKth(node->left, k, kk);
        kk++;
        if(kk == k) {
            element = node->val;
            return;
        }
        getKth(node->right, k, kk);
    }
};