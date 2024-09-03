class Solution {
public:
    bool backspaceCompare(string q, string t) {
        stack<char> s;
        for(int i=0;i<q.length();i++){
            if(q[i] == '#'){
                if(!s.empty())
                s.pop();
            }else s.push(q[i]);
        }
        string nS;
        while(!s.empty()){
            nS+=s.top();
            s.pop();
        }
        for(int i=0;i<t.length();i++){
            if(t[i] == '#'){
                if(!s.empty())
                s.pop();
            }else s.push(t[i]);
        }
        string nT;
        while(!s.empty()){
            nT+=s.top();
            s.pop();
        }
        return nS == nT;
    }
};