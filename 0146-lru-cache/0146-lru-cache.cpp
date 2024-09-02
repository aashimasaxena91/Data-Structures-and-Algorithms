class LRUCache {
public:
    unordered_map<int, int> mp;
    unordered_map<int, list<int> :: iterator> add;
    list<int> v;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            
                v.erase(add[key]);
                v.push_front(key);
                
                add[key] = v.begin();
                   
                    return mp[key];
            
           
            }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(v.size()==cap){
                int q = v.back();
                add.erase(q);
                mp.erase(q);
                v.pop_back();
            }
           
        }else{
            v.erase(add[key]);
            add.erase(key);
            mp.erase(key);
        }
            v.push_front(key);
            add[key] =v.begin();
        
            mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */