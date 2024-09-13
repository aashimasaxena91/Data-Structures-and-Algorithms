class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros=0, res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') ones++;
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                zeros++;
            }
            if(s[i]=='1')
                ones--;
            res=max(res, ones+zeros);
        }
        return res;
    }
};