class Solution {
public:
    int appendCharacters(string s, string t) {
        int sc=0, tc=0;
        while(sc<s.length() && tc<t.length()){
            if(s[sc]== t[tc]){
               
                tc++;
            }
            sc++;
        }
        return t.length()-tc;
    }
};