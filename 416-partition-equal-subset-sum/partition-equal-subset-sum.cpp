class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if((sum & 1) != 0) return false;

        int target = sum/2;

        vector<vector<bool>> dp(n, vector<bool> (target+1, 0));

        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }

        if(target == nums[0]) dp[0][nums[0]] = true;

        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                dp[i][j] = dp[i-1][j] || ((j >= nums[i]) ? dp[i-1][j-nums[i]] : 0);
            }
        }

        return dp[n-1][target];
    }

    /*bool dfs(int i, int target, vector<int>& nums, vector<vector<int>>& dp){

        if(target == 0) return true;

        if(i == 0) return (target == nums[0]);

        if(dp[i][target] != -1) return dp[i][target];

        bool pick = false;
        if(target >= nums[i]) pick = dfs(i-1, target-nums[i], nums, dp);

        bool notPick = dfs(i-1, target, nums, dp);

        return dp[i][target] = pick || notPick;
    }*/
};