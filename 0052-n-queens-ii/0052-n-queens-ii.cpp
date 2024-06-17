class Solution {
public:
    
    int soln(int n, vector<int> & up, vector<int> & tL, vector<int> & tR, int i){
        if(i>=n)
            return 1;
        int count=0;
        for(int j=0;j<n;j++){
            if(up[j]==0 && tL[n-1-i+j]==0 && tR[i+j]==0){
                up[j]=tL[n-1-i+j] = tR[i+j] = 1;
                count+=soln(n, up, tL, tR, i+1);
                up[j]=tL[n-1-i+j] = tR[i+j] = 0;
            }
        }
        return count;
    }
    
    int totalNQueens(int n) {
       
        vector<int> up(n, 0), tL(2*n, 0), tR(2*n, 0); 
        return soln(n, up, tL, tR, 0);
    }
};