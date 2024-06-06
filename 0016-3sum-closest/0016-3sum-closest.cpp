class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return -1;
        int sum =0;
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff =INT_MAX;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]== nums[i-1]) continue;
            int  l =i+1,  r= n-1;
            while(l<r){
                sum = nums[i] + nums[l] + nums[r]  ;
                int d = abs(sum - target);
                if(sum == target) return sum;
                else if(d<diff){
                    diff  = d;
                    ans = sum;
                  
                }
                
                if(sum>target){
                    r--;
                }
                else{
                    l++;
                }
                
            }
        }
        return ans;
    }
};