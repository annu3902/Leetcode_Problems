class Solution {
public:

    void dfs(int start, vector<int> nums, vector<vector<int>>& result){
        if(start == nums.size() - 1){
            result.push_back(nums);
            return;
        }

        for(int i = start; i<nums.size(); i++){
            if(i!=start && nums[i] == nums[start]){
                continue;
            }
            // if(i != start && nums[i] != nums[start]){
                 
            // }
            swap(nums[i], nums[start]);
            dfs(start+1, nums, result);
            
        }

        return;

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        // vector<int> temp = nums;
        sort(begin(nums), end(nums));
        dfs(0, nums, result);
        return result;
    }
};