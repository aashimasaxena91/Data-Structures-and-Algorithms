class Solution {
public:
    int soln(vector<int> & arr, int k){
        if(k<0) return 0;
        int res=0;
        int sum=0;
        int j=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            while(sum>k && j<=i){
                sum-=arr[j];
                j++;
            }
                res +=i-j+1;
            
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> arr =nums;
        for(int i=0;i<nums.size();i++){
            if(arr[i]%2 == 0){
                arr[i] = 0;
            }else arr[i] = 1;
        }
        return soln(arr, k) - soln(arr, k-1);
    }
};