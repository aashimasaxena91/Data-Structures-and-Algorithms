class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int res=0;
        int z=n-1;
        int l=0, r=n-1;
        while(l<r ){
            int k =min(height[l], height[r]) * (r-l);
            if(res<k){
                res  = k;
            }
           
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
            
        }
        return res;
    }
};