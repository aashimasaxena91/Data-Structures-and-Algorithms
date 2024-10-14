class Solution {
public:
    int ans(string & s, int l, int r){
        if(l>=r || l==s.size() || r==-1) return 0;
        
        
        if(s[l]==s[r]) return ans(s, l+1, r-1);
        
        else{
            int m=0;
            int i= l+1, j=r-1;
            while(i<r){
                if(s[i]==s[r]) break;
                i++;
            }
            while(j>l){
                if(s[j]==s[l] ) break;
                j--;
            }
            
            if((i-l)<=(r-j)){
                for(int k=i;k>l;k--){
                    swap(s[k], s[k-1]);
                }
                m = i-l;
            }else{
               for(int k=j;k<r;k++){
                    swap(s[k], s[k+1]);
                } 
                m = r-j;
            }
            return m+ ans(s, l+1, r-1);
        }
    }
    int minMovesToMakePalindrome(string s) {
        return ans(s, 0, s.size()-1);
    }
};