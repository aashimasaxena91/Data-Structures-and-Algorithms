class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = seats.size();
        int ans =0;
        for(int i=0;i<n;i++){
            if(seats[i]== students[i]){
                continue;
            }
            if(seats[i]<students[i])
                ans+= students[i]- seats[i];
            else
                ans+=seats[i]- students[i];
        }
        return ans;
    }
};