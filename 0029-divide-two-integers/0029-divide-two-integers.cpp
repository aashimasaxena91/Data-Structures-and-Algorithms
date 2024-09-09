class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend ==0) return 0;
        if(dividend== divisor) return 1;
        bool pos = true;
        if((divisor <0 && dividend>=0 ) || (divisor>0 && dividend<=0)) pos= false;
        long num = abs(dividend), den = abs(divisor);
        long ans=0;
        while(num>=den){
            long ct=0;
            while(num>= (den<<(ct+1)))
                ct++;
            num-=(den<<ct);
            
            ans+= 1<<ct;
        }
        
        if(ans==1<<31 && pos) return INT_MAX;
        
        if(ans==1<<31 &&!pos) return INT_MIN;
       if(!pos) ans = -ans;
        return ans;
    }
};