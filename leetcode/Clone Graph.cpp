/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    map<Node*, Node*> mp;
    
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }
        vector<Node*> nodes;
        Node *cloned = new Node(node->val, nodes);
        mp[node] = cloned;
        for (int i = 0; i < node->neighbors.size(); i++) {
            cloned->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return cloned;
    }
};
