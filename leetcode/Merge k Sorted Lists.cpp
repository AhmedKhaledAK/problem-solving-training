/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (lists.empty()) return NULL;
        
        priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
     
        ListNode* lans = NULL;
        ListNode* head = NULL;
        for(int i =0; i < lists.size(); i++){
            ListNode* l = lists[i];
            if (lists[i] != NULL) {
                lists[i] = lists[i]->next;
                pq.push(make_pair(l->val, i));
            }
        }
        while(!pq.empty()){
            pair<int, int> p;
            p = pq.top();
            pq.pop();
            if (lans == NULL) {
                lans = new struct ListNode(p.first);
                head = lans;
            } else {
                lans->next = new struct ListNode(p.first);
                lans = lans->next;
            }
            
            if (lists[p.second] != NULL) {
                pq.push(make_pair(lists[p.second]->val, p.second));
                lists[p.second] = lists[p.second]->next;
            }
        }
        
        return head;
    }
};
