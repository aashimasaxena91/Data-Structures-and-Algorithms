class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int ans=0;
        int res=0;
        int j=0;
        int zer=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == 0 ){
                q.push(i);
                zer++;
                if(zer>k && !q.empty()){
                     j = q.front()+1;
                    q.pop();
                    zer--;
                } 
                
            }
            ans= i-j+1;
            res= max(ans, res);
        }
        // if( t == 0 && !flag) return res-1;
        return res;
    }
};