class Solution {
public:
    bool hasAlternatingBits(int n) {
       int c=0;
        if(n%2==0)
         c= 1;
        else c=0;
        while(n!=0){
            int k = n%2;
            if(k==c) return false;
            c=k;
            n=n/2;
        }
        return true;
    }
};