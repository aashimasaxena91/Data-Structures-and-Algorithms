class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        if(nums.size()<2) return 0;
        // unordered_set<int> st;
        // for(int i=0;i<nums.size();i++){
        //     if(k!=0 && st.find(nums[i])!=st.end()) continue;
        //     if(st.find(nums[i]-k)!= st.end()){
        //        ans++;
        //     }
        //     if (k!=0 && st.find(nums[i]+k)!=st.end()){
        //             ans++;
        //         }
        //     st.insert(nums[i]);
        // }
        unordered_map<int, int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto m: mp){
            if(k==0){
                if(m.second>1)
                    ans++;
            }else{
            if(mp.find(m.first+k)!=mp.end()){
                ans++;

            }
            }
         
        }
        return ans;
    }
};