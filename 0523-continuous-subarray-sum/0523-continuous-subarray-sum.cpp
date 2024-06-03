class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return false;
        unordered_map<int, int> mp;
        int preSum=0;
        
        mp.insert({0,-1});
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            if(mp.find(preSum%k)!=mp.end()){
                if(i-mp[preSum%k]>1)
                    return true;
            }else{
                mp[preSum%k] = i;
            }
            
        }
        return false;
//         if(nums.size()<=1) return false;
        
//         int preSum=0;
//         unordered_map<int, int> mp;
//         for(int i=0;i<nums.size();i++){
           
//             preSum+=nums[i];
//             if( mp.find(preSum%k)!=mp.end() || preSum%k == 0){
//                 if(mp[preSum%k]>=1)
//                      return true;
//             }
            
//                 mp[preSum%k]++;
            
            
//         }
//         return false;
    }
};