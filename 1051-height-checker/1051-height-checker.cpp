class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> m = heights;
        int ans=0;
        sort(m.begin(), m.end());
        for(int i=0;i<m.size();i++){
            if(m[i]!=heights[i]) ans++;
        }
        return ans;
    }
};