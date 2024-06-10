class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        int n = nums.size();
        stack<int> s;
        for(int i=0;i<n*2;i++){
            int cur = nums[i%n];
            while(!s.empty() && nums[s.top()]< cur){
                ans[s.top() ] = cur;
                s.pop();
            }
            if(i<n) s.push(i);
        }
        return ans;
    }
};