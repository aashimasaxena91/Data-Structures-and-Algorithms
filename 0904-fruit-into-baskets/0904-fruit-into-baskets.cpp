class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n<3) return n;
        int res=0, ans=0;
         pair<int,int> a = {fruits[0],0}, b;
        int i=0, j=1;
        while(j<n &&fruits[j] == a.first){
            a.second =j;
            j++;
        }
        if(j>=n) return n;
        b = {fruits[j],j};
        j++;
        res=j;
        while(j<n){
            if(fruits[j] != a.first && fruits[j] != b.first){
                if(b.second>a.second){
                 i= a.second+1;
                 a = b;
                }else{
                    i = b.second+1;
                }
                b = {fruits[j], j};
                
            }else if(fruits[j] == a.first)
                a.second = j;
            else
                b.second = j;
            res = max(res, j-i+1);
                        j++;

        }
    return res;
    }
};