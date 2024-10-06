class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;
     
           
        for(int j = 0;j<nums.size();j++){
             pq.push(nums[j]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};