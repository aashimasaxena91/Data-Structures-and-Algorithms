class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]== nums[i-1]) continue;
            int l = i+1, r= n-1;
            while(l<r){
                int k = nums[i]+nums[l]+nums[r];
                if(k==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    
                }else if(k<0){
                    l++;
                   
                }else{
                    r--;
                  
                }
                while((l-1)!=i && l<r && nums[l]==nums[l-1]) l++;
                while((r+1)!=n && l<r && nums[r]==nums[r+1]) r--; 
            }
        }
        return ans;
    }
};