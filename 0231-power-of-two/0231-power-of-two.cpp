class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1 || (n!=1 && n%2==1)) return false;
       int k = n-1;
        int t= n^k;
        int p = (k<<1 )|1;
        if(p==t) return true;
        return false;
    }
};