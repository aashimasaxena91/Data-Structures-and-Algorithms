class Solution {
public:
    int reverse(int x) {
        int temp =0;
        // bool flag = false;
        // if(x<0) flag=true;
        // x = abs(x);
        while(x!=0){
            int l = x%10;
            x=x/10;
            if(temp >INT_MAX /10 || temp<INT_MIN/10) return 0;
            temp= temp*10 + l;
        }
        // if(flag) temp = -temp;
        return temp;
    }
};