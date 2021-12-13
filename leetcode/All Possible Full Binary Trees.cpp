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
    unordered_map<int, vector<TreeNode*>> memo;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (memo.find(n) == memo.end()) {
            vector<TreeNode*> ans;
            if (n == 1) {
                ans.push_back(new TreeNode(0));
            } else if (n % 2 == 1) {
                for (int x = 0; x < n; x++) {
                    int y = n - 1 - x;
                    for (TreeNode* left : allPossibleFBT(x)) {
                        for (TreeNode* right : allPossibleFBT(y)) {
                            TreeNode* bns = new TreeNode(0);
                            bns->left = left;
                            bns->right = right;
                            ans.push_back(bns);
                        }
                    }
                }
            }
            return memo[n] = ans;
        }
        return memo[n];
    }
};
