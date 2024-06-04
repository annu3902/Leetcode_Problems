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

        return solve(nums, 0, 0, nums[0]);
    }

    bool solve(vector<int> &nums, int index, int k, int currSum){
        if(index == nums.size()-1) return true;
        else if(mpp.find(currSum) == mpp.end()) return false;

        else if(dp[index][k] != -1) return dp[index][k];

        index = mpp[currSum];
        bool ans2 = false;
        bool ans1 = false;

        if(k>0) ans1 = solve(nums, index, k, currSum + k);
        if(k-1>0) ans2 = solve(nums, index, k-1, currSum + k-1);
        bool ans3 = solve(nums, index, k+1, currSum + k+1);

        return dp[index][k] = ans1 || ans2 || ans3;
    }
};