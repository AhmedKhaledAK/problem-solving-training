/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }
        if (mp.find(head) != mp.end()) {
            return mp[head];
        }
        
        Node* cloned = new Node(head->val);
        mp[head] = cloned;
        
        cloned->next = copyRandomList(head->next);
        cloned->random = copyRandomList(head->random);
        return cloned;
    }
};
