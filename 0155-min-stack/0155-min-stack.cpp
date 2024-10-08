class MinStack {
public:
    vector<pair<int,int>> v;
    
    MinStack() {
        
    }
    
    void push(int val) {
       if(v.empty()){
           v.push_back({val, val});
       }else{
           pair<int, int> q = v.back();
           int t = min(q.first, q.second);
           v.push_back({val, t });
       }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return min(v.back().first, v.back().second);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */