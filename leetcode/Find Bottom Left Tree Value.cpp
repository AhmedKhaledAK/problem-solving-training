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
    int maxDepth = -1;
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int depth, int& ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                ans = root->val;
            }
        }
        dfs(root->left, depth + 1, ans);
        dfs(root->right, depth + 1, ans);
    }
};
