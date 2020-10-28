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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> path;    
        dfs(root, ret, path);
        vector<string> res;
        for (vector<int> v : ret) {
            string s = "";
            for (int i : v) {
                s += to_string(i) + "->";
            }
            s.pop_back();
            s.pop_back();
            res.push_back(s);
        }
        return res;
    }
    
    void dfs(TreeNode *node, vector<vector<int>> & ret, vector<int> & path) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            path.push_back(node->val);
            ret.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(node->val);
        dfs(node->left, ret, path);
        dfs(node->right, ret, path);
        path.pop_back();
    }
};
