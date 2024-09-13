class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if(n<3) return 0;
        int l = 0, r = n-1;
        int lmax = h[0], rmax = h[n-1], ans=0;
        while(l<r){
            if(lmax<rmax){
                
                l++;
                lmax= max(lmax, h[l]);
                ans+=lmax-h[l];
            }else if(lmax>=rmax){
                 r--;
                rmax= max(rmax, h[r]);
                ans+=rmax-h[r];
            }
            
        }
        return ans;
    }
};