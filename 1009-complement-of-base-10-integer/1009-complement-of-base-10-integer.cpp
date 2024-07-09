class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int k=0;
        int i=0;
        while(n!=0){
            int bit = n&1;
            n=n>>1;
          bit=  bit==1 ? 0 : 1;
            k+=bit*pow(2,i);
            i++;
        }
        return k;
    }
};