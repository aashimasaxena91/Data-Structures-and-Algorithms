class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]] =i;
        }
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i])
                s.pop();
            if(mp.find(nums2[i])!=mp.end()){
            if(!s.empty() && s.top()>nums2[i] )
                nums1[mp[nums2[i]]] = s.top();
            else
                nums1[mp[nums2[i]]] = -1;
            }
            s.push(nums2[i]);
        }
        return nums1;
    }
};