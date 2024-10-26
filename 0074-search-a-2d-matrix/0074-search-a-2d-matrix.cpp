class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1;
        int q= -1;
        int n = matrix[0].size();
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1]>=target) {
                q = mid;
                break;
            }
            else if(matrix[mid][0]>target){
                r= mid-1;
            }else l = mid+1;
        }
        if(q==-1) return false;
        l =0, r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[q][mid] == target) return true;
            else if(matrix[q][mid]>target) r = mid-1;
            else l=mid+1;
        }
        return false;
        
    }
};