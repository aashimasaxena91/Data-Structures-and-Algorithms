class Solution {
public:
    int soln(vector<vector<int>>& grid, int m, int n, int i, int j, int sum){
        if(i<0 || i>=m || j<0 ||j>=n || grid[i][j]==0) return 0;
        
        
        int x[] = {0, 0, -1, 1};
        int y[] = {-1, 1, 0, 0};
        int ans=1;
        grid[i][j] =0;
        for(int k=0;k<4;k++){
            
            ans+=soln(grid, m,n, i+x[k], j+y[k], sum+1);
            // grid[i][j] =1;
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),  n = grid[0].size();
        int res =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res = max(res,soln(grid, m,n , i, j, 0));
                }
            }
        }
        return res;
    }
};