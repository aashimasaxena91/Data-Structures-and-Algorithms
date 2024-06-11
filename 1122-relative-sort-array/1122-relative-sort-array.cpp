class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(), arr1.end());
        vector<int> ans;
        map<int, int> mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        int i=0, j=0;
        
        for(j =0;j<arr2.size();j++){
            while(mp[arr2[j]]>0){
                ans.push_back(arr2[j]);
                i++;
                mp[arr2[j]]--;
            }
            // if(mp[arr2[j]]==0) mp.erase(arr2[j]);
           
        }
        
        for(int i=0; i<arr1.size();i++){
            if(mp[arr1[i]]!=0)
                ans.push_back(arr1[i]);
        }
        return ans;
    }
};