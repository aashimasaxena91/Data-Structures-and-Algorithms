class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int i=0, j=0;
        int ans = j-i+1, res=0;
        while(j<s.size()){
            
            if(mp.find(s[j]) != mp.end()){
                while(mp.find(s[j])!= mp.end()){
                     mp.erase(s[i]);
                   i++;
                   
               }
               
            }
             ans = j-i+1;
             res = max(ans, res);
             mp.insert(s[j]);
            j++;
        }
        return res;
    }
};