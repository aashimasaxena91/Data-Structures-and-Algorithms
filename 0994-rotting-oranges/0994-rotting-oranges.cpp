class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count=0,b =0;
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) b++;
            }
        }
        int x[] = {0,0, -1,1}, y[] = {1,-1, 0,0};
       
        while(!q.empty()){
            int s = q.size();
             bool  flag = false;
            while(s--){
                auto t = q.front();
                q.pop();
                for(int w =0;w<4;w++){
                    int i = t.first + x[w], j = t.second+y[w];
                    if(i<0 || i>=m ||j<0 ||j>=n) continue;
                    if(grid[i][j] == 1){
                        if(!flag){
                            flag = true;
                            count++;
                        }
                        grid[i][j] = 2;
                        q.push({i,j});
                        b--;
                    }
                }
            }
            
        }
        if(b!=0) return -1;
        return count;
    }
};