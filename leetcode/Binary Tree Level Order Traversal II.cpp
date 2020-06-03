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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> tree;
        tree.push(root);
        vector<int> v;
        while(!tree.empty()) {
            
            int len = (int) tree.size();
            
            while (len > 0) {
                TreeNode* node = tree.front();
                tree.pop();
                v.push_back(node->val);
                if (node->left) {
                    tree.push(node->left);
                }
                if (node->right) {
                    tree.push(node->right);
                }
                len--;
            }
            ans.push_back(v);
            v.clear();
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
