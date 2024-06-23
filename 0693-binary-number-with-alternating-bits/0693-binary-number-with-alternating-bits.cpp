class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long int k = n^(n>>1);
        if(((k+1)&k)==0) return true;
         else return false;
        
    }
};