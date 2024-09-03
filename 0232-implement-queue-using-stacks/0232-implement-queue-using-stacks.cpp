class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int k = output.top();
            output.pop();
            return k;
        }else{
            while(input.size()!=1){
                output.push(input.top());
                input.pop();
            }
            int k = input.top();
            input.pop();
            return k;
        }
    }
    
    int peek() {
        if(!output.empty()){
            int k = output.top();
           
            return k;
        }else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int k = output.top();
          
            return k;
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */