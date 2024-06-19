class Solution {
public:
    int countPrimes(int n) {
        vector<long long int> isPrime(n, true);
        int ans =0;
        for(long long int i=2;i<n;i++){
            if(isPrime[i]){
                ans++;
                
                for(long long int j=i*i;j<n;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        return ans;
    }
};