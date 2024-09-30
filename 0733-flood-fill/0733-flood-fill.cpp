class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(),  n = image[0].size();
        
        int k = image[sr][sc];
        if(k==color) return image;
        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr,sc});
        vector<int> x = {0,0,-1,1}, y ={1,-1,0,0};
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int i = t.first;
            int j = t.second;
            for(int r =0;r<4;r++){
                int iR = i+x[r], jR = j+ y[r];
                if(iR<0 || iR>=m || jR<0 || jR>=n || image[iR][jR]!=k) continue;
                image[iR][jR] = color;
                q.push({iR, jR});
            }
            
        }
        return image;
    }
};