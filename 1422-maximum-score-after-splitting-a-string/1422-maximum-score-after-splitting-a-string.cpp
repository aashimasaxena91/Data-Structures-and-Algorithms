class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros=0, res=INT_MIN;

        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                zeros++;
            }
            if(s[i]=='1')
                ones++;
            res=max(res, zeros-ones);
        }
        if(s[s.size()-1]=='1' )ones++;
        return res+ones;
    }
};