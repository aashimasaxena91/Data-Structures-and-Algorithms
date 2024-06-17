class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<=1) return true;
      long l=0, r = sqrt(c);
        while(l<=r){
            // if((l!=0 &&l>INT_MAX/l) ||( r!=0 && r>INT_MAX/r)) return false;
             long mid = l*l + r*r;
            if(mid == c) return true;
            else if(mid<c) l++;
            else r--;
        }
        return false;

        // int a = sqrt(c);
        // for(long i=0;i*i<= c;i++){
        //     double b = sqrt(c - i*i);
        //     if(b == (int)b ) return true;
        // }
        // return false;
    }
};