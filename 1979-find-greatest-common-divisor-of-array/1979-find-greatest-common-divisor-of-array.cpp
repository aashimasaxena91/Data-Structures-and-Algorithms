class Solution {
public:
    int GCD(int A, int B){
        if(B==0) return A;
        return GCD(B, A%B);
    }
    int findGCD(vector<int>& nums) {
        int minA = INT_MAX, maxB = INT_MIN;
        for(int i=0;i<nums.size();i++){
            minA= min(minA, nums[i]);
            
            maxB= max(maxB, nums[i]);
        }
        return GCD(minA, maxB);
    }
};