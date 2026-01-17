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

        vector<vector<int>> dp(n, vector<int>(2*sum+1, 0));
        dp[0][nums[0] + sum] += 1;
        dp[0][-nums[0] + sum] += 1;

        for(int i=1; i<n; i++){
            for(int j=-sum; j <=sum; j++){
                int plus = (abs(j - nums[i]) <= sum) ? dp[i-1][j - nums[i] + sum] : 0;
                int minus = (abs(j + nums[i]) <= sum) ? dp[i-1][j + nums[i] + sum] : 0;

                dp[i][j+sum] = plus+minus;
            }
        }        

        return dp[n-1][target+sum];
    }
};