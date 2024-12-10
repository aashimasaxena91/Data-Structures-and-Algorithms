class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = nums[0], ele2 = nums[0], ct1=0, ct2=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){
                ct1++;
            }else if(nums[i]==ele2){
                ct2++;
            }else if(ct1==0){
                ele1 = nums[i];
                ct1++;
            }else if(ct2==0){
                ele2= nums[i];
                ct2++;
            }else{
                ct1--;
                ct2--;
            }
        }
        ct1=0; ct2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1)
                ct1++;
            else if(nums[i]==ele2)
                ct2++;
        }
        vector<int> ans;
        if(ct1>n/3) ans.push_back(ele1);
        if(ct2>n/3) ans.push_back(ele2);
        return ans;
        
    }
};