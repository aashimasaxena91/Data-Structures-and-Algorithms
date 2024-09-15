class Solution {
public:
    int soln(vector<int>& nums, int k) {
        if(k<0) return 0;
        int res=0, j=0;
        int sum =0;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp.size()>k && j<=i){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0) mp.erase(nums[j]);
                j++;
            }
            res+=i-j+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return soln(nums, k) - soln(nums, k-1);
    }
};