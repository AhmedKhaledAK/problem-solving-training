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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> list;
        if (n == 0) {
            return list;
        }
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees (int st, int end) {
        vector<TreeNode*> list;
        if (st > end) {
            list.push_back(NULL);
            return list;
        }
        
        for (int i = st; i <= end; i++) {
            vector<TreeNode*> leftTree = generateTrees(st, i - 1);
            vector<TreeNode*> rightTree = generateTrees(i + 1, end);
            
            for (int j = 0; j < leftTree.size(); j++) {
                TreeNode* left = leftTree[j];
                for (int k = 0; k < rightTree.size(); k++) {
                    TreeNode* right = rightTree[k];
                    TreeNode* root = new TreeNode(i, left, right);
                    list.push_back(root);
                }
            }
        }
        return list;
    }
};
