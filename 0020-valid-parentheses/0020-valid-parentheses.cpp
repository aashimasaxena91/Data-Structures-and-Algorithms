class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2==1) return false;
      stack<char> k;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                k.push(s[i]);
            else{
                if(k.empty()) return false;
                char c = k.top();
                if((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '[') )
                    k.pop();
            
            
            else return false;
        }
        }
        if(!k.empty()) return false;
        return true;
    }
};