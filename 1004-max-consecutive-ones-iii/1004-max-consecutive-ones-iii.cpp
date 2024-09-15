class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    
        int ans=0;
        int res=0;
        int j=0;
        int zer=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == 0 ){
                zer++;
            }
            if(zer>k ){
                if(nums[j]==0) zer--;
                j++;
                
            } 
             ans= i-j+1;
            if( ans> res){
               
                res=ans;
            }
        }
        return res;
    }
};