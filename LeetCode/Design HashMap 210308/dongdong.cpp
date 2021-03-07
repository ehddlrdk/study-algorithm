class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> hash_key;
    vector<int> hash_value;
    
    MyHashMap() {
        hash_key;
        hash_value;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        for (int i = 0; i < hash_key.size(); i++) {
            if (key == hash_key[i]) {
                hash_value[i] = value;
                return;
            }
        }
        hash_key.push_back(key);
        hash_value.push_back(value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for (int i = 0; i < hash_key.size(); i++) {
            if (key == hash_key[i]) 
                return hash_value[i];
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for (int i = 0; i < hash_key.size(); i++) {
            if (key == hash_key[i]){ 
                hash_key.erase(hash_key.begin() + i);
                hash_value.erase(hash_value.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
