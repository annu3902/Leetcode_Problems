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

        if((sum & 1) == 1) return 0;

        vector<bool> prev(sum+1, 0);
        vector<bool> curr(sum+1, 0);
        prev[0] = true;
        curr[0] = true;
        prev[nums[0]] = true;
        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
                bool pick = (j >= nums[i]) ? prev[j - nums[i]] : 0;
                bool notPick = prev[j];

                curr[j] = pick || notPick;
            }
            prev = curr;
        }

        return prev[sum/2];
    }
};