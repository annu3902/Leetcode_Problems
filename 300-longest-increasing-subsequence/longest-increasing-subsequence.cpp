class Solution {
public:
    // int dp[];
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return solve(nums, 0, -1, dp);
    }

    int solve(vector<int> &nums, int index, int prevIndex, vector<vector<int>> &dp){
        if(index == nums.size()) return 0;

        else if(dp[index][prevIndex+1] != -1) return dp[index][prevIndex + 1];

        if(prevIndex >= 0 && nums[index] <= nums[prevIndex]){
            return dp[index+1][prevIndex+1] = solve(nums, index +1, prevIndex, dp);
        }

        else{
        // skip the element
            int ans1 = solve(nums, index + 1, prevIndex, dp);
            // pick the element
            int ans2 = 1 + solve(nums, index + 1, index, dp);

            return dp[index][prevIndex + 1] = max(ans1, ans2);
        }
    }
};