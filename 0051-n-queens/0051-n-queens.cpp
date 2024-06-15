class Solution {
public:
    
    bool isSafePos(  vector<string>& board, int i, int j, int n){
       
        int tempI = i;
        //upward
        while(tempI>=0){
            if(board[tempI][j]=='Q') return false;
            tempI--;
        }
        //topLeft
        tempI = i;
        int tempJ = j;
        while(tempI>=0 && tempJ>=0){
            if(board[tempI][tempJ]=='Q') return false;
            tempI--;
            tempJ--;
        }
        tempI = i;
         tempJ = j;
        while(tempI>=0 && tempJ<n){
            if(board[tempI][tempJ]=='Q') return false;
            tempI--;
            tempJ++;
        }
        return true;
    }
    
    void soln(vector<vector<string>> & ans, int n, int i,  vector<string>& board){
        if(i>=n){
           
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafePos(board, i,j, n)){
                board[i][j]='Q';
                soln(ans, n, i+1, board);
                board[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=0;j<n;j++){
                temp+= '.';
            }
            board.push_back(temp);
        }
        // vector<vector<char>> board(n, vector<char> (n,'.'));
        soln(ans, n, 0,board);
        return ans;
    }
};