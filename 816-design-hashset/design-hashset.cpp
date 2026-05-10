class MyHashSet {
private:
    vector<int> hashTable;
public:
    MyHashSet() {
        hashTable.resize(1e6+1, 0);
    }
    
    void add(int key) {
        hashTable[key] = true;
    }
    
    void remove(int key) {
        hashTable[key] = false;
    }
    
    bool contains(int key) {
        return hashTable[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */