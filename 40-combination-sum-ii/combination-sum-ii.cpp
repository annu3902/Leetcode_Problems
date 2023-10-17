class Solution {
public:
void helper(vector<int> &nums, int target, int ind, vector<int> &subset, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(subset);
        return;
    }

    if(ind >= nums.size() || target< nums[ind]) {
        return;
    }

    // subset.push_back(nums[ind]);
    for(int i = ind; i<nums.size();i++){
        if(i !=ind && nums[i] == nums[i-1]) continue;
        subset.push_back(nums[i]);
        helper(nums, target - nums[i], i + 1, subset, ans);
        subset.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> ans;
        helper(nums, target, 0, subset, ans);
        return ans;
    }
};