class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp1 (n+1, -1);
        vector<int> dp2 (n+1, -1);

        int ans1 = solve(nums, 0, n-2, dp1);
        int ans2 = solve(nums, 1, n-1, dp2);

        return max(ans1, ans2);
    }

    int solve(vector<int> &nums, int start, int end, vector<int> &dp){

        if(start > end) return 0;

        if(dp[start] != -1) return dp[start];

        dp[start] = max(nums[start] + solve(nums, start + 2, end, dp), solve(nums, start + 1, end, dp));

        return dp[start];
    }
};