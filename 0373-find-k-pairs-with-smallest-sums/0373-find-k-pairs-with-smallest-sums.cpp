class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        if(k==0 || nums1.size()==0 || nums2.size()==0) return ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > p;
        set<pair<int, int>> qs;
        
        
        p.push({nums1[0]+nums2[0],{0,0}});
        qs.insert({0,0});
        while(!p.empty() && k--){
            auto t = p.top();
            p.pop();
            ans.push_back({nums1[t.second.first], nums2[t.second.second]});
            auto l = t.second;
            if(l.first+1< nums1.size() && qs.find({l.first+1, l.second}) == qs.end()){
                p.push({nums1[l.first+1] + nums2[l.second], {l.first+1, l.second}});
                qs.insert({l.first+1, l.second});
            }
            if(l.second+1< nums2.size() && qs.find({l.first, l.second+1}) == qs.end()){
                p.push({nums1[l.first] + nums2[l.second+1], {l.first, l.second+1}});
                qs.insert({l.first, l.second+1});
            }
            
        }
        return ans;
    }
};