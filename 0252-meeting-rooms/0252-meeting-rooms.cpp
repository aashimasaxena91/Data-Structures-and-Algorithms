class Solution {
public:
   static  bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[i-1][1]) return false;
        }
        return true;
    }
};