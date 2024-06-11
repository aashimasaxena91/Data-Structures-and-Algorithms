class Solution {
public:
    double soln(double x, int n) {
        if(n==0) return 1;
       
        double temp = soln(x, n/2);
        temp = temp*temp;
        if(n%2==0){
            return temp;
        }else{
            return x*temp;
        }
    }
    
    double myPow(double x, int n) {
        if(n==0) return 1;
        bool flag =false;
        if(n<0) flag = true;
        double ans = soln(x, abs(n));
        if(flag == true){
            return 1/ans;
        }
        return ans;
      
    }
};