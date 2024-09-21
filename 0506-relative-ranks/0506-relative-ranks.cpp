class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<score.size();i++)
            pq.push({score[i], i});
        vector<string> t (score.size());
        int k =1;
        while(!pq.empty()){
            if(k==1){
                t[pq.top().second] = "Gold Medal";
            }else if(k==2){
                t[pq.top().second] ="Silver Medal";
            }else if(k==3){
                t[pq.top().second] = "Bronze Medal";
            }else{
                t[pq.top().second] = to_string(k);
            }
            k++;
            pq.pop();
        }
        return t;
    }
};