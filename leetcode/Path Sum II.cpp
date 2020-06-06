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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> v; 
        vector<vector<int>> ans; 
        helper(root, sum, 0, v, ans);
        return ans;
    }
    
    void helper(TreeNode* root, int sum, int acc, vector<int>& v, vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }
        acc += root->val;
        v.push_back(root->val);
        if (acc == sum && !root->right && !root->left) {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        if (acc != sum && !root->right && !root->left) {
            v.pop_back();
            return;
        }
        helper(root->left, sum, acc, v, ans);
        helper(root->right, sum, acc, v, ans);
        v.pop_back();
    }
};
