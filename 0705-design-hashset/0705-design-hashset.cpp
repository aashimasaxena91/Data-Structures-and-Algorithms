class MyHashSet {
public:
    vector<int> k;
    int s;
    MyHashSet() {
        s = 1e6+1;
        k.resize(s);
    }
    
    void add(int key) {
        k[key]=1;
    }
    
    void remove(int key) {
        k[key] = 0;
    }
    
    bool contains(int key) {
        return k[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */