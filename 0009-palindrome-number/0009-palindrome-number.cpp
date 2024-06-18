class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10 == 0)) return false;
        int rev =0;
        int temp=x;
        while(rev<temp && temp!=0){
            int k = temp%10;
             if(k>INT_MAX/10) return false;
            rev = rev*10 + k;
            temp/=10;
            
        }
        if(rev== temp) return true;
        if(rev/10==temp) return true;
        return false;
    }
};