class FirstUnique {
    
    unordered_map<int, list<int>::iterator> mp;
    list<int> q;
    
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        if (q.size() != 0) {
            return *(q.begin());
        }
        return -1;
    }
    
    void add(int value) {
        if (mp.find(value) == mp.end()) {
            q.push_back(value);
            mp[value] = prev(q.end());
        } else {
            if (mp[value] != q.end()) {    // this is the second time for this element    
                q.erase(mp[value]);
                mp[value] = q.end();
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
