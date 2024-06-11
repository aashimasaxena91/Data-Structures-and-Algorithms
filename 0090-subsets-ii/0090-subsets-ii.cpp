class Solution {
public:
    
//  vector<vector<int> > subsetsWithDup(vector<int> &S) {
//         vector<vector<int> > totalset = {{}};
//         sort(S.begin(),S.end());
//         for(int i=0; i<S.size();){
//             int count = 0; // num of elements are the same
//             while(count + i<S.size() && S[count+i]==S[i])  count++;
//             int previousN = totalset.size();
//             for(int k=0; k<previousN; k++){
//                 vector<int> instance = totalset[k];
//                 for(int j=0; j<count; j++){
//                     instance.push_back(S[i]);
//                     totalset.push_back(instance);
//                 }
//             }
//             i += count;
//         }
//         return totalset;
//         }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> soln = {{}};
        sort(nums.begin(), nums.end());
      
        for(int i=0;i<nums.size();){
            int c=0;
            while(c+i<nums.size() && nums[c+i]== nums[i] )c++;
            int k = soln.size();
            for(int l=0;l<k;l++){
                vector<int> temp = soln[l];
                for(int a =0;a<c;a++){
                    temp.push_back(nums[i]);
                    soln.push_back(temp);
                }
            }
            i+=c;
        }
        return soln;
    }
};