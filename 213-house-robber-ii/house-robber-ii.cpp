class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(dfs(0, n-2, nums), dfs(1, n-1, nums));
    }

    int dfs(int start, int end, vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n-1, 0);

        dp[0] = nums[start];

        for(int i=start+1; i<=end; i++){
            int op1 = dp[i-1-start];
            int op2 = ((i-2 >= start) ? dp[i-2-start] : 0) + nums[i];
            dp[i - start] = max(op1, op2);
        }
        return dp[n-2];
    }
};