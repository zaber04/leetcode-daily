class RandomizedSet {
    vector<int> items;
    unordered_map<int, int> map;

    bool itemExists(int item) {
        if (map.find(item) != map.end()) {
            return true;
        }

        return false;
    }
public:
    RandomizedSet() {
        
    }
    
    bool insert(int item) {
        if (itemExists(item)) {
            return false;
        }

        this->items.push_back(item);
        map[item] = this->items.size() - 1;

        return true;
    }
    
    bool remove(int item) {
        if (!itemExists(item)) {
            return false;
        }

        auto it = map.find(item);
        this->items[it->second] = this->items.back();
        this->items.pop_back();
        map[this->items[it->second]] = it->second;
        map.erase(item);

        return true;
    }
    
    int getRandom() {
        return this->items[rand() % this->items.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */