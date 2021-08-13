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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> tree;
        int currLevel, ans;
        currLevel = ans = 1;
        int currSum = 0;
        int maxSum = root->val;
        tree.push(root);
        bool notNulls = false;
        while (!tree.empty()){
            int len = tree.size();
            while (len != 0) {
                TreeNode* node = tree.front();
                tree.pop();
                notNulls = notNulls ? true : (node->left || node->right);
                if (node->left) {
                    currSum += node->left->val;
                    tree.push(node->left);
                }
                if (node->right) {
                    currSum += node->right->val;
                    tree.push(node->right);
                }
                len--;
            }
            currLevel++;
            if (notNulls && currSum > maxSum) {
                maxSum = currSum;
                ans = currLevel;
            }
            currSum = 0;
            notNulls = false;
        }
        return ans;
    }
};