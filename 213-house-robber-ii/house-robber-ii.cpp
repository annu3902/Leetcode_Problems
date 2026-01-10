class Solution {
private:
    int dfs(int node, vector<int>& nums, vector<int>& dp){
        if(node == 0) return dp[node] = nums[0];

        if(dp[node] != -1) return dp[node];

        int op1 = nums[node] + ((node >= 2) ? dfs(node-2, nums, dp) : 0);
        int op2 = (node >= 1) ? dfs(node-1, nums, dp) : 0;

        dp[node] = max(op1, op2);
        return dp[node];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> nums1;
        vector<int> nums2;

        for(int i=0; i<nums.size()-1; i++){
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i+1]);
        }

        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);

        dfs(n-2, nums1, dp1);
        dfs(n-2, nums2, dp2);

        return max(dp1[n-2], dp2[n-2]);
    }
};