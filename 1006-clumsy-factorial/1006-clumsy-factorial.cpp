class Solution {
public:
    int clumsy(int n) {
        stack<int> s;
        int op=0;
        s.push(n);
        for(int i=n-1;i>=1;i--){
            if(op==0){
                int x = s.top();
                s.pop();
                s.push(x*i);
            }else if(op==1){
                 int x = s.top();
                s.pop();
                s.push(x/i);
            }else if(op==2)
                s.push(i);
            else
                s.push(i*(-1));
            op = (op+1)%4;
        }
        int ans =0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};