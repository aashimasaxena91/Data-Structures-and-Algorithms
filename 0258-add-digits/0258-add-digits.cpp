class Solution {
public:
    int addDigits(int nums) {
        if(nums<10) return nums;
        return addDigits(nums%10 + addDigits(nums/10));
    }
};