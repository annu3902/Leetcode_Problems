class Solution {
public:

    // int dp[2501][2501];
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));

        vector<int> dp(n, 1);

        for(int i=1; i<n; i++){

            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    // dp[i] -> Longest increasing subsequence ending at the index i.
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

        }

        return *max_element(dp.begin(), dp.end());

    }
    

    // Recursion + MEmoization
    // int solve(vector<int> &nums, int index, int prevIndex){
    //     if(index == nums.size()) return 0;

    //     else if(prevIndex != -1 && dp[index][prevIndex] != -1) return dp[index][prevIndex];

    //     if(prevIndex >= 0 && nums[index] <= nums[prevIndex]){
    //         return dp[index+1][prevIndex] = solve(nums, index +1, prevIndex);
    //     }

    //     else{
    //     // skip the element
    //         int ans1 = solve(nums, index + 1, prevIndex);
    //         // pick the element
    //         int ans2 = 0;
    //         if(prevIndex == -1 || nums[prevIndex] < nums[index])
    //             ans2 = 1 + solve(nums, index + 1, index);

    //         if(prevIndex != -1) 
    //             dp[index][prevIndex] = max(ans1, ans2);

    //         return max(ans1, ans2);
    //     }
    // }
};