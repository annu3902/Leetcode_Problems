class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[i].push_back(nums[i]);
        }

        int maxSize = 0;
        vector<int> ans;

        for(int i = 0; i<n; i++){

            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    vector<int> temp = mp[j];
                    temp.push_back(nums[i]);
                    if(temp.size() > mp[i].size()){
                        mp[i] = temp;
                    }
                }
            }
            if(maxSize < mp[i].size()){
                maxSize = mp[i].size();
                ans = mp[i];
            }
        }

        // int maxSize = 0;
        // vector<int> ans;
        // for(pair<int, vector<int>> it : mp){
        //     if(maxSize < it.second.size()){
        //         maxSize = it.second.size();
        //         ans = it.second;
        //     }
        // }

        return ans;
    }
};