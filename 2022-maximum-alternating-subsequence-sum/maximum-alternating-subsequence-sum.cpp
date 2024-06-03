class Solution {
public:
    // long long maxAlternatingSum(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<vector<long long>> dp(n+1, vector<long long> (2, -1));
        
    //     // State 
    //         // dp[i][even] -> forming a even length till ith element
    //         // dp[i][odd] -> forming an odd length till the ith element

    //     // BaseCases 
    //     dp[0][0] = 0;
    //     dp[0][1] = 0;
        
    //     for(int i=1; i<=n; i++){
    //         // Even        take                      notTake
    //         dp[i][0] = max(dp[i-1][1] - nums[i-1], dp[i-1][0]);
    //         // odd         take                       notTake
    //         dp[i][1] = max(dp[i-1][0] + nums[i-1], dp[i-1][1]);

    //     }

    //     return max(dp[n][0], dp[n][1]);

    //     // return solve(nums, 0, 0, dp);

    // }

    // long long solve(vector<int> &nums, bool index, int currIndex, vector<vector<long long>> &dp){
    //         if(currIndex >= nums.size()) return 0;

    //         else if(dp[currIndex][index] != -1) return dp[currIndex][index];
    //         // not take 
    //         long long ans1 = solve(nums, index, currIndex + 1, dp);

    //         // take

    //     long long ans2 = solve(nums, 1-index, currIndex + 1, dp) + nums[currIndex]*((index & 1) ? -1 : 1);
            

    //         return dp[currIndex][index] = max(ans1, ans2);

    // }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(2, vector<long long> (2, -1));

        // BaseCases 
        dp[0][0] = 0; // known state for even length
        dp[0][1] = 0; // known state for odd length
        
        for(int i=1; i<=n; i++){
            // Even        take                      notTake
            dp[1][0] = max(dp[0][1] - nums[i-1], dp[0][0]);
            // odd         take                       notTake
            dp[1][1] = max(dp[0][0] + nums[i-1], dp[0][1]);

            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }

        return max(dp[1][0], dp[1][1]);
    }

};