class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum & 1 != 0) return false;

        int target = sum/2;

        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return dfs(n-1, target, nums, dp);
    }

    bool dfs(int i, int target, vector<int>& nums, vector<vector<int>>& dp){

        if(target == 0) return true;

        if(i == 0) return (target == nums[0]);

        if(dp[i][target] != -1) return dp[i][target];

        bool pick = false;
        if(target >= nums[i]) pick = dfs(i-1, target-nums[i], nums, dp);

        bool notPick = dfs(i-1, target, nums, dp);

        return dp[i][target] = pick || notPick;
    }
};