class Solution {
public:

    void dfs(vector<int> &vis, int node,vector<vector<int>>& adj){
        
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(vis, it,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>> adjLs(n);

        //matrix to list
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]==1  && i!=j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
               dfs(vis, i,adjLs);
            }
        }
        return count;
    }

};