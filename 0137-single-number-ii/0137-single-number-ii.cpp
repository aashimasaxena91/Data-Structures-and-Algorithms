class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int aloneBit =0;
        
        for(int i=0;i<32;i++){
            int bitSum=0;
            for(int k=0;k<nums.size();k++){
                if((nums[k]>> i) & 1){
                    bitSum++;
                }
            }
            int t=0;
            if(bitSum%3==1){
                aloneBit = aloneBit | (1<<i);
            }
        }
        return aloneBit;
    }
};