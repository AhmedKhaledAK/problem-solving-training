class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto e : stones) 
            pq.push(e);
        
        while (pq.size() > 1) { 
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x == y) continue;
            int diff = max(x,y) - min(x,y);
            pq.push(diff);
        }
        
        if (pq.empty()) return 0;
        return pq.top();
    }
};
