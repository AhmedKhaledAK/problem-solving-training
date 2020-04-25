class LRUCache {
private:
    //            key       val, list position  --->>> to get O(1)
    unordered_map<int, pair<int, list<int>::iterator>> value;
    list<int> lrulist;  // hold KEYS not VALUES
    int capacity;
    
    
    void erase (int key) {
        auto it = value.find(key);
        assert(it != value.end());
        lrulist.erase(it->second.second);
        value.erase(it);
    }
    
    void push (int key, int v) {
        lrulist.push_back(key);
        value[key] = {v, prev(lrulist.end())};
    }
    
public:
    LRUCache(int cap) {
        this->capacity = cap;
    }
    
    int get(int key) {
        auto it = value.find(key);
        if (it == value.end()) {
            return -1;
        }
        int v = it->second.first;
        erase(key);
        push(key, v);
        return v;
    }
    
    void put(int key, int v) {
        if (value.find(key) != value.end()) {
            erase(key);
        }
        if ((int) value.size() == capacity) {
            assert(!lrulist.empty());
            erase(lrulist.front());
        }
        push(key, v);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
