class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k =3;
        vector<pair<int, int>> temp (k-1, {INT_MIN, 0});
        
        for(int i=0;i<nums.size();i++){
            int j;
            for(j=0;j<k-1;j++){
                if(temp[j].first == nums[i]){
                    temp[j].second++;
                    break;
                }
            }
            if(j==k-1){
                int l;
                for(l=0;l<k-1;l++){
                    if(temp[l].second == 0){
                         temp[l] = {nums[i], 1};
                        break;
                    }
                }
                if(l==k-1){
                    for(int h=0;h<k-1;h++){
                        temp[h].second--;
                    }
                }
            }
        }
        for(int i=0;i<temp.size();i++){
            temp[i].second =0;
            
        }
        vector<int> ans;
        for(int j=0;j<k-1;j++){
            int ac=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==temp[j].first){
                    ac++;
                    
                }
            }
            if(ac>nums.size()/3){
                        ans.push_back(temp[j].first);
                    }
        }
        return ans;
    }
};