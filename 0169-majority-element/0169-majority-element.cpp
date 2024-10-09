class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = INT_MIN;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                ele = nums[i];
            }
            if(nums[i]==ele)
                c++;
            else
                c--;
        }
        return ele;
    }
};