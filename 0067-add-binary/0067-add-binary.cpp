class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length()-1, n2 = b.length()-1;
        int carry = 0;
        string ans;
        while(n1>=0 || n2>=0 || carry==1){
            int l =0, r=0;
            if(n1>=0){
                l = int(a[n1--]-'0');
            }
            if(n2>=0){
                r = int(b[n2--]-'0');
            }
            int c = l + r+ carry;
            carry =0;
            if(c == 0 ){
                ans = '0'+ans;
            }else if(c==1){
                ans = '1'+ans;
                
            }else if(c==2){
                ans = '0'+ans;
                carry =1;
            }else{
                ans = '1'+ans;
                carry =1;
            }
            
        }
        return ans;
    }
};