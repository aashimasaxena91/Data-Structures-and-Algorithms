class Solution {
public:
    long long int squareSum(long long int n){
        long long int temp=0;
         while(n!=0){
            long long int l = n%10;
            temp += l*l;
            n/=10;
        }
        return temp;
    }
    bool isHappy(int n) {
       
        long long int l=n, r=n;
        unordered_map<long long int, long long int> mp;
        do{
            if(mp.find(l)==mp.end()){
                long long int q = squareSum(l);
                mp[l] = q;
            } 
            l = mp[l];
            
            long long int w=0;
            if(mp.find(r)==mp.end()){
                w = squareSum(r);
                mp[r] = w;
            }
                w = mp[r];
            
           if(mp.find(w)==mp.end()){
                long long int q = squareSum(w);
                mp[w] = q;
            }
            r = mp[w];
            
        }while(l!=r);
        
        if (1 == l) return true;
        
        else return false;
    }
};