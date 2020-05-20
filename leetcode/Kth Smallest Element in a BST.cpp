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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, smallest = INT_MIN;
        traverse(root, k, cnt, smallest);
        return smallest;
    }
    
    void traverse (TreeNode* node, int k, int& cnt, int& smallest) {
        if (smallest != INT_MIN) {
            return;
        }
        if (node == NULL) {
            return;
        }
        traverse(node->left, k, cnt, smallest);
        if (++cnt == k) {
            smallest = node->val;
        }
        traverse(node->right, k, cnt, smallest);
    }
};
