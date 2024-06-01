class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(0, nums, dp, n);

        // if(n == 1){
        //     return (nums[0]);
        // }

        // // dp[i] -> ith index tak ka collection
        
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        // for(int i=2; i<n; i++){

        //     int op1 = dp[i-2] + nums[i];
        //     int op2 = dp[i-1];
 
        //     dp[i] = max(op1, op2);
        // }

        // return dp[n-1];
    }

    int solve(int index, vector<int> &nums, vector<int> &dp, int n){

        if(index >= n){
            return 0;
        }

        else if(dp[index] != -1) return dp[index];
        int op1 = nums[index] + solve(index + 2, nums, dp, n);
        int op2 = solve(index + 1, nums, dp, n);

        dp[index] = max(op1, op2);
        return dp[index];
    }
};