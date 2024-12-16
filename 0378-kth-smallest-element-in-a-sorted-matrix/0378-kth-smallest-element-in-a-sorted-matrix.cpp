class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)>>1;
            int smallerEquals = countt(matrix, mid, n);
            if(smallerEquals>=k){
                ans = mid;
                high = mid-1;
            }else low=mid+1;
        }
        return ans;
    }
    
    int countt(vector<vector<int>>& matrix, int mid, int n){
        int j = n-1;
        int ans=0;
      for(int i=0;i<n;i++){
          
            while( j>=0 && matrix[i][j]>mid){
                j--;
            }
                ans+=j+1;
            
        }
        return ans;
    }
};