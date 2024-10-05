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
            if(i!=0 && (s[i] == 'V' ||s[i] == 'X')){
                if(s[i-1] == 'I'){
                    i--;
                    l=l-1;
                }
            }else if(i!=0 && (s[i] == 'L' ||s[i] == 'C')){
                if(s[i-1] == 'X'){
                    i--;
                    l=l-10;
                }
            } else if(i!=0 && (s[i] == 'D' ||s[i] == 'M')){
                if(s[i-1] == 'C'){
                    i--;
                    l=l-100;
                }
            }
            k+=l;
            i--;
        }
        return k;
    }
};