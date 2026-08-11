class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = true;

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=nums[i]; j++){
                if(dp[j + i] == true){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};