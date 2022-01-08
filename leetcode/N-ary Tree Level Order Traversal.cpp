/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> level;
        level.push_back(root->val);
        ans.push_back(level);
        level.clear();
        
        queue<Node*> tree;
        tree.push(root);
        while(!tree.empty()) {
            int len = tree.size();
            while (len > 0) {
                Node* node = tree.front();
                tree.pop();
                vector<Node*> children = node->children;
                for (int i = 0; i < children.size(); i++) {
                    tree.push(children[i]);
                    level.push_back(children[i]->val);
                }
                len--;
            }
            if (!level.empty()) {
                ans.push_back(level);
                vector<int> temp;
                level = temp;
            }
        }
        return ans;
    }
};
