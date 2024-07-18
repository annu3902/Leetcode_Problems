class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }

    int solve(vector<int> &nums, int start, int end){
        vector<int> dp(end-start+1, 0);
        int n = dp.size();
        if(n==1) return nums[start];

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);

        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i+start]);
        }
        return dp[n-1];
    }
};