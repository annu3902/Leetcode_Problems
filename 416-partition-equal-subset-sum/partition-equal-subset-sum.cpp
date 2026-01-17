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
        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum & 1 == 1) return 0;

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;
        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
                bool pick = (j >= nums[i]) ? dp[i-1][j - nums[i]] : 0;
                bool notPick = dp[i-1][j];

                dp[i][j] = pick || notPick;
            }
        }

        return dp[n-1][sum/2];
    }
};