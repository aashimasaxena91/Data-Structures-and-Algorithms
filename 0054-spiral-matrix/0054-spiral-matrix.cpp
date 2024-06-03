class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int top =0, bot = mat.size()-1, left = 0, right = mat[0].size()-1;
        while(top<=bot && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            
            for(int i=top;i<=bot;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(top<=bot){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bot][i]);
            }
            bot--;
            }
            if(left<=right){
            for(int i=bot;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
            }
        }
        return ans;
    }
};