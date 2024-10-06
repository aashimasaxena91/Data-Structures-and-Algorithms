class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=-1, r= nums.size(),  i =0;
        while(i<r){
            if(nums[i]==0){
                l++;
                swap(nums[l], nums[i]);
                i++;
            }else if(nums[i]==2){
                r--;
                swap(nums[r], nums[i]);
            }else i++;
        }
        
    }
};