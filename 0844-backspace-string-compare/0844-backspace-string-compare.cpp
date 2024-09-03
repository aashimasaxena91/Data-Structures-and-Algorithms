class Solution {
public:
    bool backspaceCompare(string q, string t) {
        stack<char> s, w;
        for(int i=0;i<q.length();i++){
            if(q[i] == '#'){
                if(!s.empty())
                s.pop();
            }else s.push(q[i]);
        }
       
        for(int i=0;i<t.length();i++){
            if(t[i] == '#'){
                if(!w.empty())
                w.pop();
            }else w.push(t[i]);
        }
        if(s.size()!=w.size()) return false;

        while(!s.empty() && !w.empty()){
            if(s.top()!=w.top()) return false;
            w.pop();
            s.pop();
        }
       return true;
    }
};