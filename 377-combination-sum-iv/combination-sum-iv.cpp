class Solution {
public:
    int f(int target, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(target < 0) return 0; // if target is smaller than 0 there will be no combinations

        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];

        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans += f(target-nums[i], nums, dp);
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, -1);
        return f(target, nums, dp);
    }
};