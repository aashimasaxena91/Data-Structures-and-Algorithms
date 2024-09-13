class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int tsum = 0;
        int minn = INT_MAX;
        bool p = false;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
            if(tsum<0) p=true;
            minn = min(minn, tsum);
        }
        if(p) return abs(minn)+1;
        
        return 1;
    }
};