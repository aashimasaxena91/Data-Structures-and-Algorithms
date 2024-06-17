class Solution {
public:
    
    bool isSafePos(int i, int j, int n, vector<string> board, vector<int>& up,  vector<int>& tLeft,  vector<int> & tRight ){
//         int tempI = i, tempJ = j;
//         while(tempI>=0){
            
//             if(board[tempI][j] == 'Q') return false;
//             tempI--;
//         }
//         tempI = i;
//         while(tempI>=0 && tempJ>=0){
//            if(board[tempI][tempJ] == 'Q') return false;
//             tempI--;
//             tempJ--;
//         }
//          tempI = i;
//         tempJ=j;
//         while(tempI>=0 && tempJ<=n){
//            if(board[tempI][tempJ] == 'Q') return false;
//             tempI--;
//             tempJ++;
//         }
        if(up[j]==1) return false;
        if(tRight[i+j] == 1) return false;
        if(tLeft[n-1-i+j]==1) return false;
        return true;
    
    }
    
    void soln(int n, vector<vector<string>> &ans,  vector<string> & board, int i,  vector<int>& up,  vector<int>& tLeft,  vector<int> & tRight ){
        
        if(i>=n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafePos(i,j,n, board, up, tLeft, tRight)){
                board[i][j] = 'Q';
                up[j] =1;
                tLeft[n-1-i+j] = 1;
                tRight[i+j] = 1;
                soln(n,ans, board,i+1, up, tLeft, tRight);
                board[i][j] = '.';
                up[j]=0;
                tLeft[n-1-i+j] = 0;
                tRight[i+j] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        for(int i=0;i<n;i++){
            string temp ="";
            for(int j=0;j<n;j++){
                temp+=".";
            }
            board.push_back(temp);
        }
        vector<int> up(n,0);
        vector<int> tLeft(2*n, 0);
        vector<int> tRight(2*n, 0);
        soln(n, ans, board, 0, up, tLeft, tRight);
        return ans;
    }
};