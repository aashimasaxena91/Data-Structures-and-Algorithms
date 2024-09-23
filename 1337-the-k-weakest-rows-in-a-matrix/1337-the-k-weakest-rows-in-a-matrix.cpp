class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int j) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<mat.size();i++){
            int w=0;
            for(int k=0;k<mat[i].size();k++){
                if(mat[i][k]==0) break;
                w++;
            }
            pq.push({w, i});
        }
        
        vector<int> ans;
        for(int m=0;!pq.empty() && m<j;m++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};