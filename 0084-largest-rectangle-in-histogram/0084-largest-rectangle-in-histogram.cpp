class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans =0;
        int res=0;
        stack<int> s;
        vector<int> pS (heights.size(),0);
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                ans = max(ans, heights[s.top()] * (i-pS[s.top()]-1));
                s.pop();
            }
            
            pS[i] = s.empty() ? -1 : s.top();
            s.push(i);
        
                          
        }
        int k = heights.size();
        
        while(!s.empty()){
            ans = max(ans, heights[s.top()] * (k-pS[s.top()]-1));
        
                s.pop();
        }
        
        return ans;
        
    }
};