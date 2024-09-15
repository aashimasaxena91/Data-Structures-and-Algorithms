class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l=0, r=0;
        int res=0;
        int t=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            t=max(t, mp[s[i]]);
            if((i-l+1)-t > k) 
            {
                 mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            
             res = max(res, i-l+1);
        }
        return res;
    }
};