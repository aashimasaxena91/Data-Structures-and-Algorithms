class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string c = strs[0];
        if(c.empty()) return c;
        for(int i=1;i<strs.size();i++){
            int k=0;
            while(k<c.size() && k<strs[i].size()){
                if(c[k] != strs[i][k])
                    break;
                k++;
            }
            if(k!= c.size()){
                c = c.substr(0,k);
            }
            if(c == "" ) return c;
        }
        return c;
    }
};