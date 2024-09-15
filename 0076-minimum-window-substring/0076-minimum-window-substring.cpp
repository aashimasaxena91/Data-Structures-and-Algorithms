class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX, start = -1;
        int l =0,r = 0;
        int ct=0;
        vector<int> hash(256, 0);
        for(auto k:t){
            hash[k]++;
        }
        while(r<s.size()){
            if(hash[s[r]]>0) ct++;
            hash[s[r]]--;
             while(ct>=t.size() ){
                if(ct == t.size() && minLen> r-l+1){
                    minLen = r-l+1;
                    start = l;
                } 
                hash[s[l]]++;
                if(hash[s[l]]>0) ct--;
                l++;
                
            }
            
            r++;
           
        }
        return start == -1 ? "" : s.substr(start, minLen);
    }
};