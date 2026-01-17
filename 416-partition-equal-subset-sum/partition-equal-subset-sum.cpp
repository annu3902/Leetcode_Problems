class Solution {
bool dfs(int index, int sum, int totalSum, vector<int>& nums, vector<vector<int>>& dp){
    if(index == -1){
        return 2*sum == (totalSum);
    }

    if(dp[index][sum] != -1) return dp[index][sum];

    bool pick = dfs(index-1, sum + nums[index], totalSum, nums, dp);
    bool notPick = dfs(index-1, sum, totalSum, nums, dp);

    return dp[index][sum] = pick || notPick;
}

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);

        vector<vector<int>> dp(n, vector<int>(totalSum+1, -1));
        return dfs(n-1, 0, totalSum, nums, dp);
    }
};