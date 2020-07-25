/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node *ans;
public:
    Node* flatten(Node* head) {
        if (!head) {
            return NULL;
        }
        ans = new struct Node(-1);
        Node* temp = ans;
        solve(head);
        temp->next->prev = NULL;
        return temp->next;
    }
    
    void solve(Node *node) {
        if (!node) {
            return;
        }
        Node *n = new struct Node(node->val);
        ans->next = n;
        n->prev = ans;
        ans = n;
        solve(node->child);
        solve(node->next);
    }
};
