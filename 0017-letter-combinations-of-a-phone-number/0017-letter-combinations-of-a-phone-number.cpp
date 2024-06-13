class Solution {
public:
    
    void soln(string digits, int n, map<char, vector<char>> mp, string temp, vector<string>& res, int i ){
        
        if(i>=n){
            res.push_back(temp);
            return;
        }
        for(int p = 0;p<mp[digits[i]].size();p++){
            temp[i] = mp[digits[i]][p];
            soln(digits, n, mp, temp, res, i+1 );
        }
        
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> res;
        if(n==0) return res;
        map<char, vector<char>> mp;
        int k=0;
        int t = 3;
        char two = '0';
        for(int i=2;i<=9;i++){
            if(i==7 || i==9) t=4;
            else t=3;
            for(int j=0;j<t;j++){
                mp[two + i].push_back('a'+ k);
                k++;
            }
        }
        // string temp=digits;
      
        string temp = digits;
        // for(int i = 0;i<n;i++){
        //     temp+=mp[digits[i]][0];
        // }
         soln( digits, n, mp, temp, res, 0 );
     
        return res;
    }
};