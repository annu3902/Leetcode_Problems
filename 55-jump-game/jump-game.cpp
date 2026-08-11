class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 0);
        // dp[n-1] = true;
        int lastReachableIndex = n-1;

        for(int i=n-2; i>=0; i--){
            if(i + nums[i] >= lastReachableIndex){
                lastReachableIndex = i;
            }  
        }

        return (lastReachableIndex == 0) ? true : false;
    }
};