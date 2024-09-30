class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& v, int m, int n, int baseI, int baseJ){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0) return;
        grid[i][j] = 0;
        v.push_back({i-baseI,j-baseJ});
        vector<int> x = {0,0,-1,1}, y = {-1,1,0,0};
        for(int q =0;q<4;q++){
            int iR = i+ x[q], jC = j+ y[q];
            dfs(grid, iR, jC, v, m, n, baseI, baseJ);
        }
        
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> s;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vector<pair<int, int>> v;
                    dfs(grid, i, j, v, m , n, i, j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};