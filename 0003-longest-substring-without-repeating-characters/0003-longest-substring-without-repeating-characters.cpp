class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp (255, -1);
        // unordered_map<char, int> mp;
        int i=0, j=0;
        int ans = j-i+1, res=0;
        while(j<s.size()){
            
            if(mp[s[j]] != -1 && mp[s[j]]>=i){
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