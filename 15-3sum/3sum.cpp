class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result;
        sort(begin(nums), end(nums));

        for(int i=0; i<n; i++){

            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int target = -nums[i];

            vector<vector<int>> ans = twoSum(nums, target, i);

            if(ans.size() > 0){
                for(int j=0; j<ans.size(); j++){
                    ans[j].push_back(nums[i]);
                    result.push_back(ans[j]);
                }
                
            }

        }
        return result;
    }

    vector<vector<int>> twoSum(vector<int> &nums, int target, int index){
        int n = nums.size();

        vector<vector<int>> result;
        vector<int> ans;
        unordered_map<int, int> mp;

        for(int i=index+1; i<n; i++){

            if(mp.count(target - nums[i])){
                ans.push_back(target-nums[i]);
                ans.push_back(nums[i]);
                result.push_back(ans);
                ans.clear();
                while (i + 1 < n && nums[i] == nums[i + 1]) i++; // skipping the similar numbers
            }

            
            mp[nums[i]] = i;
        }
        return result;
    }
};