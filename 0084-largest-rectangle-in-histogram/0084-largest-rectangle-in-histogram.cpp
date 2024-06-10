class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int  n = nums.size();
        if(n==1) return nums[0];
        vector<int> nG(n,n);
        vector<int> pG(n, -1);
        stack<int> s,q;
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]<=nums[s.top()]){
                s.pop();
            }
            if(!s.empty())
                nG[i] = s.top();
            s.push(i);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[i]<=nums[q.top()]){
                q.pop();
            }
            if(!q.empty())
                pG[i] = q.top();
            q.push(i);
            ans = max(ans, nums[i] * (nG[i] - pG[i] - 1));
        }
        return ans;
        
    }
};