class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i=0, j=0;
        int ans = j-i+1, res=0;
        while(j<s.size()){
            
            if(mp.find(s[j]) != mp.end() && mp[s[j]]>=i){
                i = mp[s[j]]+1;
               
            }
               
            
             ans = j-i+1;
             res = max(ans, res);
             mp[s[j]] = j;
            j++;
        }
        return res;
    }
};