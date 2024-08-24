class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n  = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n+1, vector<int> (d+1, -1));
        return dfs(n-1, d, jobDifficulty, dp);
    }

    int dfs(int index, int days, vector<int>& nums, vector<vector<int>> &dp){
        
        // Base Case
        if(days == 1 && index >= 0){
            int maxi = INT_MIN;
            for(int i=index; i>=0; i--){
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }

        if(index < 0){
            return 1e9;
        }

        if(dp[index][days] != -1) return dp[index][days];

        int mini = 1e9;

        for(int i=index; i>=0; i--){
            int maxi = INT_MIN;

            for(int j=index; j>=i; j--){
                maxi = max(maxi, nums[j]);
            }

           int ans = maxi + dfs(i-1, days-1, nums, dp);

           mini = min(mini, ans);
        }

        return dp[index][days] = mini;
    }
};