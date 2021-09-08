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
    pair<TreeNode*, int> dfs(TreeNode* node, int depth)
    {
        if (!node)
        {
            return {node, depth};
        }
        auto left = dfs(node->left, depth + 1);
        auto right = dfs(node->right, depth + 1);
        auto maxPair = left;
        if (right.second > left.second)
        {
            maxPair = right;
        } 
        else if (right.second == left.second)
        {
            maxPair.first = node;
        }
        return maxPair;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto p = dfs(root, 0);
        return p.first;
    }
};
