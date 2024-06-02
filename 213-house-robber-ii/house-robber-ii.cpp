class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return (max(nums[0], nums[1]));
         
        vector<int> dp1(n+1, 0);
        vector<int> dp2(n+1, 0);

        dynamicProgramming(nums, dp1, 0, n-2);
        dynamicProgramming(nums, dp2, 1, n-1);

        return max(dp1[n-2], dp2[n-1]);

    }

    void dynamicProgramming(vector<int> &nums, vector<int> &dp, int start, int end){
        int n = nums.size();
        dp[start] = nums[start];
        if(start != end)dp[start + 1] = max(nums[start], nums[start + 1]);

        for(int i=start +2; i<=end; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
    }
};