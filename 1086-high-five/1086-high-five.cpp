class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        sort(items.begin(), items.end());
       
        vector<vector<int>> ans;
        for(int i=0;i<items.size();){
             priority_queue<int, vector<int>, greater<int>> pq;
            pq.push(items[i][1]);
            int k=i+1;
            int l =items[i][1];
            int j=0;
            while(k<items.size() &&  items[k][0] == items[k-1][0]){
                pq.push(items[k][1]);
                l+=items[k][1];
                if(pq.size()>5){ 
                    int w = pq.top();
                    pq.pop();
                    l-=w;
                }
                if(pq.size()==5)
                    j = l/5;
                k++;
         
            }
     
            ans.push_back({items[i][0], j});
            i = k; 
        }
        return ans;
        
    }
};