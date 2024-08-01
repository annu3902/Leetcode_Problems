class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(begin(nums), end(nums), 0);

        if(total_sum & 1 != 0) return false;

        int sum = total_sum/2;

        vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));

        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }

        if(nums[0] <= sum) dp[0][nums[0]] = true;

        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j] | ((nums[i] <= j) ? dp[i-1][j-nums[i]] : 0);
            }
        }

        return dp[n-1][sum];
    }
};