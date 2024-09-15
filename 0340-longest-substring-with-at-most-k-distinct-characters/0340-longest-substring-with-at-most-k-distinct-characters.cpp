class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int l=0,r=0, res=0;
        while(r<s.length()){
            mp[s[r]]++;
            if(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if(mp.size()<=k)
                res=max(res, r-l+1);
            r++;
        }
          return res;  
    }
};