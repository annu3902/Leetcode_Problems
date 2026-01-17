class Solution {
private:
    int dfs(int index, int target, vector<int>& nums, vector<vector<int>>& dp, int sum){
        if(index < 0){
            return target == 0;
        }
        if(abs(target) > sum) return 0;

        if(dp[index][target + sum] != -1) return dp[index][target + sum];

        int plus = dfs(index - 1, target - nums[index], nums, dp, sum);
        int minus = dfs(index - 1, target + nums[index], nums, dp, sum);

        return dp[index][target + sum] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);

        if(abs(target) > sum) return 0;

        vector<vector<int>>dp(n, vector<int>(2*sum + 1 , -1));
        return dfs(n-1, target, nums, dp, sum);
    }
};