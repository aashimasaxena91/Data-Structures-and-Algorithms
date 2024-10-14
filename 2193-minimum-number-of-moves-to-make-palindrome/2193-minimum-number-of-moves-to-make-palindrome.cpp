class Solution {
public:

    int minMovesToMakePalindrome(string s) {
        int l =0, r = s.size()-1;
        int ans=0;
        
        while(l<r){
            if(s[l]!=s[r]){
                int i=l+1;
                while(i<r){
                    if(s[i]==s[r]) break;
                    i++;
                }
                if(i==r){   //for middle element case eg: abb   -->here a is middle element
                    swap(s[i], s[i-1]);
                    ans++;
                    continue;
                }
                for(int k= i;k>l;k--)
                    swap(s[k], s[k-1]);
                int m = i-l;
                ans+= m;
                }
            l++;
            r--;
        }
        return ans;
    }
};