class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(auto k: stones){
            pq.push(k);
        }
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b= pq.top();
            pq.pop();
            int t=abs( b-a);
            if(t) pq.push(t);
        }
        return pq.empty() ? 0 : pq.top();
    }
};