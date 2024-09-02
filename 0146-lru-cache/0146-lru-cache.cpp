class LRUCache {
public:
    unordered_map<int, list<pair<int, int>> :: iterator> mp;
    list<pair<int, int>> v;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        auto it =mp[key];
        pair<int, int> q = *it;
        v.erase(mp[key]);
        v.push_front(q);
        mp[key] = v.begin();
        return q.second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            v.erase(mp[key]);
            
        }else{
            if(v.size() == cap){
                auto w = v.back();
                mp.erase(w.first);
                v.pop_back();
            }
        }
         v.push_front({key, value});
         mp[key] = v.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */