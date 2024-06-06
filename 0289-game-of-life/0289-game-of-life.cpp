class Solution {
public:
    
    void checkPos(vector<vector<int>>& board, int i, int j, int m, int n ){
        int live =0;
                  //l, r, u, d, dl, dr, ur, ul
        int x[8] = {0, 0, -1, 1, 1, 1, -1, -1};
        int y[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
        for(int l = 0;l<8;l++){
            int newX = i+x[l], newY = j+ y[l];
            if(newX>=0 &&  newX<m && newY>=0 && newY <n){
                if(board[newX][newY] == 1 || board[newX][newY] == 5)
                    live++;
            }
        }
        if(board[i][j] == 0 || board[i][j] == 2){ //death case
            if(live == 3){
                board[i][j] = 4; //lives 0 -> 1
            }
        }else{ //live case
            if(live<2 || live > 3) board[i][j] = 5; //dies 1->0 
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
     
        // 0 to 1 => 4
        // 1 to 0 => 5
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                checkPos(board, i,j,board.size(),board[0].size());
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==4) board[i][j]=1;
                if(board[i][j]==5) board[i][j]=0;
                
            }
        }
    }
};