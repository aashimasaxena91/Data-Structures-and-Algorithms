class Solution {
public:
    string inve(string m){
        for(int i=0;i<m.size();i++){
            if(m[i]=='0') m[i]='1';
            else m[i] = '0';
        }
        reverse(m.begin(), m.end());
        return m;
    }
    char findKthBit(int n, int k) {
        string m="0";
        for(int i=2;i<=n;i++){
            m = m + '1' + inve(m);
            
        }
        return m[k-1];
    }
};