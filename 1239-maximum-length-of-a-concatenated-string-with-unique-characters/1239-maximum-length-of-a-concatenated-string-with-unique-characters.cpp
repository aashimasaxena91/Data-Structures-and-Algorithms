class Solution {
public:
    
    bool isRepeat(string str,vector<int> &v ){
        vector<int> self(26,0);
        for(int i=0;i<str.size();i++){
            if(self[str[i] - 'a'] ==1) return false;
            self[str[i] - 'a'] =1;
        }
        for(int i=0;i<str.size();i++){
            if(v[str[i] - 'a'] ==1) return false;
            
        }
        return true;
    }
    
    int soln(vector<string>& arr, int n,  vector<int> &v, int i, int curLen ){
        
        if(i>=n){
            return curLen;
        }
        
        if(!isRepeat(arr[i], v)){
            return soln(arr,n, v, i+1, curLen);
        }
        
        
        curLen = curLen+ arr[i].size();
        for(int q =0;q<arr[i].size();q++){
            v[arr[i][q] - 'a'] = 1;
        }
        int op1  = soln(arr,n, v,i+1, curLen);
        
         for(int q =0;q<arr[i].size();q++){
            v[arr[i][q] - 'a'] = 0;
        }
        curLen = curLen- arr[i].size();
        int op2  = soln(arr,n, v,i+1, curLen);
        return max(op1, op2);
    }
    
    int maxLength(vector<string>& arr) {
        
        
        vector<int> v(26,0);
        return soln(arr, arr.size(), v, 0, 0);
        
    }
};