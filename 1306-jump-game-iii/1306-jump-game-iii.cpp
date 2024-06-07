class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start>=arr.size()) return false;
        if(arr[start] == 0) return true;
        if(arr[start] == -1 ) return false;
        int l = arr[start];
        arr[start] =-1;
        bool flag = canReach(arr, start+ l) || canReach(arr, start-l);
        
        return flag;
    }
};