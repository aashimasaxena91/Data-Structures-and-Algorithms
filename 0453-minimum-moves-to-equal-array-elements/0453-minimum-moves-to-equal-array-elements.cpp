class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int n= nums.size();
        // sort(nums.begin(), nums.end());
        int minStep=0;
        int mn = INT_MAX;
        for(int x: nums) mn = min(mn, x);
        for(int x:nums) minStep+= x-mn;
        return minStep;
    }
};