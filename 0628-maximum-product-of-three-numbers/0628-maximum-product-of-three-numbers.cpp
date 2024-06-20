class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
      int min1=INT_MAX, min2=INT_MAX, max1 = INT_MIN, max3 = INT_MIN, max2 = INT_MIN;
        int j=nums.size()-1;
       for(int x:nums){
           if(x>max1){
               max3 = max2;
               max2 = max1;
               max1 = x;
           }else if(x>max2){
               max3 = max2;
               max2 = x;
           }else if(x>max3)max3 = x;
           
           if(x<min1){
               min2 = min1;
               min1 = x;
           }else if(x<min2){
               min2 = x;
           }
       }
        return max(min1*min2*max1 , max1*max2*max3);
    }
};