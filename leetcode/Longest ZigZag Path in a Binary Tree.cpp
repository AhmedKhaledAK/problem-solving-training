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
    int longestZigZag(TreeNode* root) {
        ans = INT_MIN;
        rec(root, 0, true);
        return ans;
    }
    void rec(TreeNode* root, int curr, bool isLeft) {
        if (!root) {
            return;
        }
        ans = max(curr, ans);
        if (isLeft) {
            rec(root->left, 1, isLeft);
            rec(root->right, curr + 1, !isLeft);
        } 
        else {
            rec(root->left, curr + 1, !isLeft);
            rec(root->right, 1, isLeft);
        }
    }
    
};
