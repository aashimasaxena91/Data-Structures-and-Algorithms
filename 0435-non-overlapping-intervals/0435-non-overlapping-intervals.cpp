class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int count =0, left =0, right =1;
        while(right<intervals.size()){
            if(intervals[right][0]>=intervals[left][1]){
                left= right;
                right++;
            }else if(intervals[left][1]>intervals[right][1]){
                left = right;
                right++;
                count++;
            }else
            {
                right++;
                count++;
            }
        }
        return count;
    }
};