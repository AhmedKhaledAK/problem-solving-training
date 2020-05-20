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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> nodes;
        TreeNode* curr = root;
        while (curr != NULL || !nodes.empty()) {
            while (curr != NULL) {
                nodes.push(curr);
                curr = curr->left;
            }
            curr = nodes.top();
            ans.push_back(curr->val);
            nodes.pop();
            curr = curr->right;
        }
        return ans;
    }
};
