class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(auto a: nums){
            mp[a]++;
        }
        
        for(auto t: mp){
            q.push({t.second, t.first});
            if(q.size()>k)
                q.pop();
        }
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
        
    }
};