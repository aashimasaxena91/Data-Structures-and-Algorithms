class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {

        int l =0, r= n.size()-1;
        while(l<r){
            int k = n[l]+n[r];
            if(k==target){
                return {l+1, r+1};
            }else if(k<target)
                l++;
            else
                r--;
        }
        return {-1, -1};
    }
};