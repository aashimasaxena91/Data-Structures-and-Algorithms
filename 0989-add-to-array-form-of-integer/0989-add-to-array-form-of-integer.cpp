class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i=n-1;
        int carry =0;
        while(i>=0 || k!=0 || carry!=0){
            int t=0;
            if(k!=0) {
                t = k%10;
                k=k/10;
            }
            int m = 0;
            if(i>=0) m = num[i];
            int sum = m + t+carry;
            carry = sum/10;
            if(i>=0){
                num[i] = sum%10;
                i--;
            }
            else
                num.insert(num.begin(), sum%10);
        }
        return num;
       
    }
};