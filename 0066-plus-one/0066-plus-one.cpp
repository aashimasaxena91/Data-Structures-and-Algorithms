class Solution {
public:
    vector<int> plusOne(vector<int>& k) {
        int carry =0;
        for(int i= k.size()-1;i>=0;i--){
            int m= k[i];
            if(i==k.size()-1) m++;
             m+=carry;
            if(m>9) carry = 1;
            else carry = 0;
            k[i] = m%10;
        }
        if(carry ==1){
            k.insert(k.begin(), 1);
            // swap(k[0], k[1]);
        }
        return k;
    }
};