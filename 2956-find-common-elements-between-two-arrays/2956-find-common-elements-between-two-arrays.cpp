class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int a=0, b=0;
        unordered_map<int, int> mp;
        for(auto k: nums1){
            mp[k]++;
        }
        for(auto t:nums2){
            if(mp.find(t)!=mp.end()){
                a+=mp[t];
                mp[t]=0;
                b++;
            }
        }
        return {a,b};
    }
};