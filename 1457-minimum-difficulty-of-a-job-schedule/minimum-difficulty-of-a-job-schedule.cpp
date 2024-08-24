class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int days) {
        int n  = jobDifficulty.size();
        if(n < days) return -1;
        vector<vector<int>> dp(n, vector<int> (days+1, -1));

        // Tabulation

        // Step1 Base Case
        // if(days == 1){
        //     for(int i=0; i<n; i++){
        //         int maxi = max_element(begin(nums), nums.begin()+i )
        //     }
        // }


        return dfs(n-1, days, jobDifficulty, dp);
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

        int maxi = INT_MIN;
        int mini = 1e9;
        for(int i=index; i>=0; i--){

            maxi = max(maxi, nums[i]);
            // for(int j=index; j>=i; j--){
            // }

           int ans = maxi + dfs(i-1, days-1, nums, dp);

           mini = min(mini, ans);
        }

        return dp[index][days] = mini;
    }
};