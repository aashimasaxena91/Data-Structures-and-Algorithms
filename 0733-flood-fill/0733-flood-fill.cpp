class Solution {
public:
    
    void soln(vector<vector<int>>& image,int m, int n, int color, int i, int j,vector<int> & x,vector<int>& y, int oldC){           if(i<0 || i>=m || j<0 || j>=n  ) return;
        if(image[i][j]!= oldC) return;
        image[i][j] = color;
        for(int k =0;k<4;k++){ 
            soln(image,m, n, color, i+x[k],j+y[k], x,y, oldC);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();
        int oldC = image[sr][sc];
        if(oldC== color) return image;
        vector<int> x = {-1,1,0,0};
        vector<int> y = {0, 0, -1,1};
        
        soln(image,m, n, color,sr,sc, x, y , oldC);
        return image;
    }
};