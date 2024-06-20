class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            // if(i!= 0 && nums[i]==nums[i-1]) continue;
            int l=i+1, r=n-1;
            while(l<r){
                int k = nums[i]*nums[l]*nums[r];
                if(k>ans){ ans = k;
                          l++;
                          while(l<r && nums[l]==nums[l-1]) l++;
                         }
                else{
                    r--;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }

            }
        }
        return ans;
    }
};