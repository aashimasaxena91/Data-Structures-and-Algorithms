class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = matrix.size();
        vector<int> colPointer (n,0);
        for(int i=0;i<min(n, k);i++){
            pq.push({matrix[i][0], i});
        }
        while(--k){
            auto curr = pq.top();
            pq.pop();
            int row_ind = curr.second;
            if(colPointer[row_ind]<n-1){
                colPointer[row_ind]++;
                pq.push({matrix[row_ind][colPointer[row_ind]], row_ind});
            }
        }
        return pq.top().first;
    }
};