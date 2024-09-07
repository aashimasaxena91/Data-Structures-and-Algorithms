class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long bitmask =0;
        for(auto k :nums){
            bitmask^= k;
        }
        long t = (bitmask & (bitmask-1)) ^ bitmask;
        int notFound=0, found=0;
        for(auto k: nums){
            if(k&t){
                notFound^= k;
            }else
                found^=k;
        }
        return {found, notFound};
    }
};