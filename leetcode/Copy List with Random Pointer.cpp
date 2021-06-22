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
    unordered_map<Node*, Node*> copiedList;
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }
        if (copiedList.find(head) != copiedList.end()) {
            return copiedList[head];
        }
        
        Node* copiedNode = new Node(head->val);
        
        copiedList[head] = copiedNode;
        
        copiedNode->next = copyRandomList(head->next);
        copiedNode->random = copyRandomList(head->random);
        
        return copiedNode;
    }
};