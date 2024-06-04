class Solution {
public:
    int n;
    unordered_map<int, int> mpp;
    int dp[2001][2001];

    bool canCross(vector<int>& nums) {
        n = nums.size();
        for(int i=0; i<n; i++){
            mpp[nums[i]] = i;
        }
        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, 0);
    }

    bool solve(vector<int> &nums, int index, int k){
        if(index == n-1) return true;

        if(mpp.find(nums[index] + k) == mpp.end()) return false;

        if(dp[index][k] != -1) return dp[index][k];

        // cout<<1<<" ";
        index = mpp[nums[index] + k] ;
        bool ans2 = false;
        bool ans1 = false;
        bool ans3 = false;
 
        if(k > 0) ans1 = solve(nums, index, k);
        if(k-1 > 0) ans2 = solve(nums, index, k-1);
        if(k+1 > 0) ans3 = solve(nums, index, k+1);

        return dp[index][k] = ans1 || ans2 || ans3;
    }
};