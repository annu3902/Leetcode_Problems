class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<vector<int>>& ans){
        int n = nums.size();

        // Base Condition -1)
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        } 

        // To do small task first -2)
        for(int i=ind; i<n; i++){
            swap(nums[i], nums[ind]);
            // Call recursion to do the remaining task
            solve(nums, ind+1, ans);

            // Backtracking
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};