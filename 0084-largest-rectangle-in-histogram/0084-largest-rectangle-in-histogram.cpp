class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans =0;
        int res=0;
        stack<int> s;
        int pS=0;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                int t = s.top();
                s.pop();
                 pS = s.empty() ? -1 : s.top();
                ans = max(ans, heights[t] * (i-pS-1));
                
            }
            
           
            s.push(i);
        
                          
        }
        int k = heights.size();
        
        while(!s.empty()){
            int t = s.top();
                s.pop();
                 pS = s.empty() ? -1 : s.top();
            ans = max(ans, heights[t] * (k-pS-1));

        }
        
        return ans;
        
    }
};