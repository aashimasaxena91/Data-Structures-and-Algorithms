class Solution {
public:
    int partition(vector<int> & nums, int l, int r){
        int pivot = nums[r];
        int i = l-1;
        while(l<r){
            if(nums[l] < pivot){
                i++;
                swap(nums[l], nums[i]);
            }
            l++;
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int  l = 0, r= nums.size()-1;
         k = nums.size()-k+1;
        while(l<=r){
            int p = partition(nums, l, r);
            if(p==k-1) return nums[p];
            else if(p<k-1) l = p+1;
            else r=p-1;
        }
        return -1;
    }
};