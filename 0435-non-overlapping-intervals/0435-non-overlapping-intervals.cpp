class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1 ) return 0;
        sort(intervals.begin(), intervals.end(), comp);
        int ct =1, f = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=f){
                ct++;
                f = intervals[i][1];
            }
        }
        return intervals.size()-ct;
    }
};