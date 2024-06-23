class Solution {
public:
    int hammingWeight(int n) {
        int c =0;
        while(n!=0){
           int k= n&1;
            c+=k;
          n=  n>>1;
        }
        return c;
    }
};