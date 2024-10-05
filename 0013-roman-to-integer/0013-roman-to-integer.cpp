class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] =1;
        mp['V'] =5;
        mp['X'] = 10;
        mp['L']=50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int i= s.size()-1;
        int k=0;
        while(i>=0){
            int l = mp[s[i]];
            if(i!=0 && (mp[s[i]] >mp[s[i-1]])){
                      i--;
                    l=l-mp[s[i]];
                }
            
            k+=l;
            i--;
        }
        return k;
    }
};