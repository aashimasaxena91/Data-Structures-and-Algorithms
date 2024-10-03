class Solution {
public:
    int countSubstrings(string s) {
        int ans=1;
        
        for(int i=1;i<s.size();i++){
            int  l=i-1,r=i+1;
            ans++;
            while(l>=0 && r<s.size() && s[l] == s[r]){
                l--;
                r++;
                ans++;
            }
            l = i-1;
            r = i;
            while(l>=0 && r<s.size() && s[l] == s[r]){
                l--;
                r++;
                ans++;
            }
        }
        return ans;
    }
};