class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return;
        int zero=0, one =0, two = n-1;
        while(one<=two){
            if(nums[one]==0){
                
                swap(nums[zero], nums[one]);
                zero++;
                one++;
               
               
            }else if(nums[one]==2){
                
                swap(nums[one], nums[two]);
                two--;
            }
            else
            one++;
        }
    }
};