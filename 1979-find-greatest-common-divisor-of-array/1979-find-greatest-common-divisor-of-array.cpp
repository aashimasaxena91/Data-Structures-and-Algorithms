class Solution {
public:

    int findGCD(vector<int>& nums) {
        int minA = INT_MAX, maxB = INT_MIN;
        for(int i=0;i<nums.size();i++){
            minA= min(minA, nums[i]);
            
            maxB= max(maxB, nums[i]);
        }
        
        while(maxB!=0){
            int temp = minA%maxB;
            minA = maxB;
            maxB = temp;
        }
        return minA;
    }
};