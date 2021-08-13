/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        vector<Node*> level = {root};
        while (!level.empty()) {
            int nlevel = level.size();
            vector<Node*> nextLevel = {};
            Node* prev = NULL;
            for (int i = 0; i < nlevel; i++) {
                if (level[i]->left) {
                    nextLevel.push_back(level[i]->left);
                    if (prev) prev->next = level[i]->left;
                    prev = level[i]->left;
                }
                if (level[i]->right) {
                    nextLevel.push_back(level[i]->right);
                    if(prev) prev->next = level[i]->right;
                    prev = level[i]->right;
                }
            }
            if (prev) prev->next = NULL;
            level = nextLevel;
        }
        return root;
    }
};