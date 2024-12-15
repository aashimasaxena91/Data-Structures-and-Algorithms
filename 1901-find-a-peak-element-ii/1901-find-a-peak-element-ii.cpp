class Solution {
public:
    int upperBD(vector<vector<int>> mat, int i, int l, int r){
        pair<int, int> ans ={INT_MIN, -1};
        for(int k = l;k<=r;k++){
           if(ans.first<mat[i][k]){
               ans = {mat[i][k], k};
           }
        }
        return ans.second;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n= mat[0].size();
        int l =0, r = m-1;
        while(l<=r){
            int mid = (l+r)/2;
            int maxElCol = upperBD(mat, mid, 0,n-1);
            if((mid ==0 || mat[mid][maxElCol]> mat[mid-1][maxElCol]) &&(mid ==m-1 || 
                mat[mid][maxElCol]> mat[mid+1][maxElCol]))
            {
                return {mid, maxElCol};
            }else if(mid!=0 && mat[mid][maxElCol]<mat[mid-1][maxElCol])
                r = mid-1;
            else l = mid+1;
        }
        return {-1,-1};
    }
};