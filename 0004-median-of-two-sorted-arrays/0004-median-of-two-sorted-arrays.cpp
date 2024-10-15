class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int k = (nums1.size()+nums2.size()+1)/2;
        int low = 0, high = nums1.size();
        while(low<=high){
            int mid1 = low+(high-low)/2;
            int mid2 = k- mid1;
            int l1 = mid1-1>=0 ? nums1[mid1-1] : INT_MIN;
            int l2 = mid2-1>=0 ? nums2[mid2-1]:INT_MIN;
           
            int r1 = mid1<nums1.size() ? nums1[mid1]:INT_MAX;
            int r2 = mid2<nums2.size() ? nums2[mid2]:INT_MAX;
            if(l1<=r2 && l2<=r1){
                if((nums1.size()+nums2.size())%2 ==1) return max(l1, l2);
                else{
                   return (double)(max(l1, l2)+min(r1, r2))/2.0;
                }
            }else if(l1>r2) high--;
            else
                low++;
        }
        return 0;
    }
};