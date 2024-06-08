class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        sort(ho.begin(), ho.end());
        sort(ve.begin(), ve.end());
        int maxH =ho[0], maxW = ve[0];
        for(int i=1;i<ho.size();i++){
            maxH = max(maxH, ho[i]-ho[i-1]);
        }
        maxH = max(maxH,h- ho[ho.size()-1]);
        for(int i=1;i<ve.size();i++){
            maxW = max(maxW, ve[i]-ve[i-1]);
        }
        maxW = max(maxW,w- ve[ve.size()-1]);
        int ans= (int)(((long long)maxH*maxW)%1000000007);
        return ans;
    }
};