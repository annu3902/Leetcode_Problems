class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        long long sum = 0;
        vector<vector<long long>> dp(n+1, vector<long long> (2, -1));
        return solve(nums, 0, 0, dp);

    }

    long long solve(vector<int> &nums, bool index, int currIndex, vector<vector<long long>> &dp){
            if(currIndex >= nums.size()) return 0;

            else if(dp[currIndex][index] != -1) return dp[currIndex][index];
            // not take 
            long long ans1 = solve(nums, index, currIndex + 1, dp);

            // take

        long long ans2 = solve(nums, 1-index, currIndex + 1, dp) + nums[currIndex]*((index & 1) ? -1 : 1);
            
            // cout<<ans1<<" "<<ans2<<endl;

            return dp[currIndex][index] = max(ans1, ans2);

    }

};