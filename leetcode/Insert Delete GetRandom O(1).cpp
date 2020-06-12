class RandomizedSet {
    
private:
    unordered_map<int, int> lookup;
    vector<int> elements;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(lookup.find(val) != lookup.end()) return false;
            elements.emplace_back(val);
            lookup[val] = elements.size() - 1;
            return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(lookup.find(val) == lookup.end()) return false;
        lookup[elements.back()] = lookup[val];      
        elements[lookup[val]] = elements.back();
        elements.pop_back();                
        lookup.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(elements.size() == 0) return 0;
        return (elements[rand() % elements.size()]);
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
