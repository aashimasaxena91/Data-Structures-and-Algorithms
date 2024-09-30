class Solution {
public:
    
    void dfs(vector<vector<char>>& grid , int i, int j, int m, int n){
        
        if(i<0 || j<0 || i==m  || j==n ||  grid[i][j]=='0') return;
        grid[i][j] = '0';
        int x[] = {0,0,1,-1};
        int y[] = {1,-1, 0, 0};
        for(int h=0;h<4;h++){
            // if(grid[i+x[h]][j+y[h]] == '1'){
                dfs( grid, i+x[h], j+y[h], m, n);
            // }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // vector<vector<int>> isVis(grid.size(), vector<int> (grid[0].size(), 0));
        int m = grid.size(), n =  grid[0].size() , count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs( grid, i, j, m, n);
                }
            }
        }
        return count;
    }
};