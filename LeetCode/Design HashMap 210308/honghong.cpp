class MyHashMap {
public:
    
    vector<int> MyKey;
    vector<int> MyValue;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        MyKey.clear();
        MyValue.clear();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        vector<int>::iterator pos = find(MyKey.begin(), MyKey.end(), key);
        
        if(pos != MyKey.end()) {
            MyValue[pos - MyKey.begin()] = value;
        }
        else {
            MyKey.push_back(key);
            MyValue.push_back(value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        vector<int>::iterator pos = find(MyKey.begin(), MyKey.end(), key);
        if(pos != MyKey.end()) {
            return MyValue[pos - MyKey.begin()];
        }
        else {
            return -1;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vector<int>::iterator pos = find(MyKey.begin(), MyKey.end(), key);
        if(pos != MyKey.end()) {
            MyKey.erase(pos);
            MyValue.erase(MyValue.begin() + (pos - MyKey.begin()));
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