class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int m, int n, int i, int j, int k){
        if(k>=word.size()) return true;
        if(i<0|| i>=m ||j<0 || j>=n || board[i][j]=='.' || board[i][j] != word[k] ) return false;
        if(word.size()==1 && board[i][j] == word[k]) return true;
        
        board[i][j] = '.';
      int x[4] = {1,0,0,-1};
        int y[4] = {0,-1,1,0};
        bool w = false;
        for(int p = 0;p<4;p++){
            w = w || solve(board, word, m, n, i+x[p], j+ y[p], k+1);
        }
        board[i][j] = word[k];
        return w;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if(m<1 || n<1) return false;
        if(word == "" ) return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                   if(solve(board, word, m, n, i, j, 0)) return true;
                }
                
            }
        }
        return false;
    }
};