class MyHashSet {
private:
    vector<list<int>> ls;
    int M;

    int getIndex(int key){
        return key % M;
    }

public:
    MyHashSet() {
        M = 12000;
        ls.resize(M, list<int>{});
    }
    
    void add(int key) {
        int index = getIndex(key);

        auto it = find(ls[index].begin(), ls[index].end(), key);

        if(it == ls[index].end()){
            ls[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);

        auto it = find(ls[index].begin(), ls[index].end(), key);

        if(it != ls[index].end()){
            ls[index].erase(it);
        }
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        auto it = find(ls[index].begin(), ls[index].end(), key);
        return it != ls[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */