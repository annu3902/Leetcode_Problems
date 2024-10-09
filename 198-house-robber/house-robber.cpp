class Solution {
public:
    int dfs(int index, vector<int>& nums, vector<int>& dp){

        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + ((index >= 2) ? dfs(index - 2, nums, dp) : 0);
        int skip = dfs(index - 1, nums, dp);

        return dp[index] = max(pick, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for(int i=1; i<n; i++){
            int op1 = dp[i-1];
            int op2 = nums[i] + ((i >= 2) ? dp[i-2] : 0);
            dp[i] = max(op1, op2);
        }

        return dp[n-1];
    }
};