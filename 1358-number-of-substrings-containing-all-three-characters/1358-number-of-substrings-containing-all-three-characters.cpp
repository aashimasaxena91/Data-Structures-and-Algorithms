class Solution {
public:
    int numberOfSubstrings(string s) {
       unordered_map<char,int>mp;
        int res=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
            if(mp.size()==3){
                int k = min(mp['a'], min(mp['b'], mp['c']));
                res+= k+1;
            }
        }
        return res;
    }
};