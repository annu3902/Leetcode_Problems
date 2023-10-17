class Solution {
public:
void helper(vector<int> &nums, int target, int ind, vector<int> &subset, vector<vector<int>> &ans){
    if(target == 0){
        // vector<vector<int>> :: iterator it;
        // it = find(ans.begin(), ans.end(), subset);
        // if(it == ans.end())
        ans.push_back(subset);
        return;
    }

    if(ind >= nums.size() || target< nums[ind]) {
        return;
    }

    // for(int i = ind; i<nums.size();i++){
    //     if(i !=ind && nums[i] == nums[i-1]) continue;
    //     subset.push_back(nums[i]);
    //     helper(nums, target - nums[i], i + 1, subset, ans);
    //     subset.pop_back();
    // }

    subset.push_back(nums[ind]);
    helper(nums, target - nums[ind], ind + 1, subset, ans);

    subset.pop_back();
    while(ind + 1 < nums.size() && nums[ind] == nums[ind + 1]){
        ind++;
    }
    helper(nums, target, ind+1, subset, ans);

}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> ans;
        helper(nums, target, 0, subset, ans);
        return ans;
    }
};

// class Solution {
// public:
// void helper(vector<int> &nums, int target, int ind, vector<int> &subset, vector<vector<int>> &ans){
//     if(target == 0){
//         ans.push_back(subset);
//         return;
//     }

//     if(ind >= nums.size() || target< nums[ind]) {
//         return;
//     }

//     // subset.push_back(nums[ind]);
//     for(int i = ind; i<nums.size();i++){
//         if(i !=ind && nums[i] == nums[i-1]) continue;
//         subset.push_back(nums[i]);
//         helper(nums, target - nums[i], i + 1, subset, ans);
//         subset.pop_back();
//     }
// }
//     vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         vector<int> subset;
//         vector<vector<int>> ans;
//         helper(nums, target, 0, subset, ans);
//         return ans;
//     }
// };

// class Solution{
//     vector<vector<int>> combinationSum2(vector<int>& nums, int target){
//         sort(nums.begin(), nums.end());

//         for(int i = nums.size() -1; i >= 0;i--){
//             if(i != nums.size() -1 && nums[i] == nums[i-1]) continue;
//             subset.push_back(nums[i]);
//             helper(nums, target - nums[i], i + 1, subset, ans);
//             subset.pop_back();
//         }
//     }
// };