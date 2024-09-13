class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        
        if(n<3) return 0;
        vector<int> lh (n), rh(n);
        lh[0] = height[0];
        rh[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            lh[i] = max(lh[i-1], height[i]);
        }
        for(int i=n-2;i>=0;i--){
            rh[i] = max(rh[i+1], height[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            ans+= min(lh[i], rh[i]) - height[i];
        }
        return ans;
    }
};