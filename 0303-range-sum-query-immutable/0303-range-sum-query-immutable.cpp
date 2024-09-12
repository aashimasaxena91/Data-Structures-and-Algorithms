class NumArray {
public:
    vector<int> k;    
    NumArray(vector<int>& nums) {
        k.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            k.push_back(k[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return k[right];
        return k[right]-k[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */