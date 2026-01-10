class Solution {
private:
    int dfs(int node, vector<int>& nums, vector<int>& dp){
        if(node == 0) return nums[node];

        if(dp[node] != -1) return dp[node];

        dp[node] = max(nums[node] + ((node >= 2) ? dfs(node-2, nums, dp) : 0) , ((node >= 1) ? dfs(node-1, nums, dp) : 0));

        return dp[node];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        // dp[i] ->max money till ith house
        vector<int> dp(n, -1);
        dfs(n-1, nums, dp);
        // dp[0] = nums[0];
        // dp[1] = max(dp[0], nums[1]);

        // for(int i=2; i<n; i++){
        //     dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        // }

        return dp[n-1];
    }
};