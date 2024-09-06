class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0) return 0;
        int n = s.size();
        int ans =0;
        int i=0;
        while(i<n && s[i]==' ')
            i++;
        bool positive = true;
        if(i<n &&( s[i]=='+' || s[i]=='-' )){
            if( s[i]=='-')  positive =false;
            i++;
            
        }
        while(i<n && isdigit(s[i])){
            if(s[i]!= 0){
                int k = s[i] - '0';
                if(ans>INT_MAX/10 ||(ans==INT_MAX/10 && k>7 ) ){
                    if(!positive) return INT_MIN;
                      return INT_MAX; 
                }
                ans = ans*10 + k;
                
            }
            i++;
        }

        if(positive)
        return ans;
        else return -ans;
    }
};