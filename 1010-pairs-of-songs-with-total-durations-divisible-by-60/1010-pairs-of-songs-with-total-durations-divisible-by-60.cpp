class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n= time.size();
        if(n<2) return 0;
        int count =0;
        unordered_map<int, int> k;
        for(int i=0;i<n;i++){
           int a = time[i]%60;
           if(a == 0)
               count+=k[a];
            else
                count+=k[60-a];
            k[a]++;
        }
        return count;
    }
};