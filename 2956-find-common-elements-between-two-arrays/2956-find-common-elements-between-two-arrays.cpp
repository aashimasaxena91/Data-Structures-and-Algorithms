class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int a =0, b=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                i++;
                j++;
               
                int l=0, r=0;
                while(i<nums1.size() && nums1[i]==nums1[i-1]){i++; l++;}
                 while(j<nums2.size() && nums2[j]==nums2[j-1]){j++; r++;}
                a=a+l+1;
                b = b+r+1;
            }else if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return {a, b};
    }
};