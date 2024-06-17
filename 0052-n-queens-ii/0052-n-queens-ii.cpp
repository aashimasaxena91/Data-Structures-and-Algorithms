class Solution {
public:
    
    int soln(int n, vector<int> & up, vector<int> & tL, vector<int> & tR, int i, int ans){
        if(i>=n)
            return 1+ans;
        for(int j=0;j<n;j++){
            if(up[j]==0 && tL[n-1-i+j]==0 && tR[i+j]==0){
                up[j]=tL[n-1-i+j] = tR[i+j] = 1;
                ans=soln(n, up, tL, tR, i+1, ans);
                up[j]=tL[n-1-i+j] = tR[i+j] = 0;
            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        int ans =0;
        vector<int> up(n, 0), tL(2*n, 0), tR(2*n, 0); 
        return soln(n, up, tL, tR, 0, ans);
    }
};