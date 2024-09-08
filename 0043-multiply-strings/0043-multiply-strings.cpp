class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        if(( num1=="0") || ( num2=="0")) return "0";
        vector<int> temp (n1+n2, 0);
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                temp[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                temp[i+j] +=temp[i+j+1]/10;
                temp[i+j+1]%=10;
            }
        }
        int i=0;
        while(i<temp.size() && temp[i]==0) i++;
        string ans= "";
        while(i<temp.size()){
            
            ans+=(temp[i] + '0');
            i++;
        }
        return ans;
    }
};