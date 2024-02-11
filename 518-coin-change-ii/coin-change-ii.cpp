class Solution {
public:

    int solve(int amount , vector<int> & coins , int index,vector<vector<int>> &dp){
        if(amount==0) return 1;
        if(index>=coins.size()) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];

        int pick = 0;
        if(amount>=coins[index]) pick = solve(amount-coins[index] , coins , index,dp);

        int notpick = solve(amount , coins , index+1,dp);

        return dp[index][amount] = pick + notpick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1 , vector<int>(n+1,0));
        
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }

        int k = amount;
        for(int amount = 1;amount<=k;amount++){
            for(int index=n-1;index>=0;index--){
                int pick = 0;
                if(amount>=coins[index]) pick = dp[amount-coins[index]][index];

                int notpick = dp[amount][index+1];

                dp[amount][index] = pick + notpick;
            }
        }
        return dp[k][0];
    }
};






// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<int> dp(amount + 1, 0);
//         dp[0] = 1;

//         for(int i = 1; i <= amount; ++i){
//             int ways = 0;
//             for(int j = 0; j < coins.size(); j++){
//                 if(i-coins[j] >= 0 && dp[i-coins[j]] > 0)
//                     ways ++;
//             }
//             dp[i] = ways;
//         }
//         return dp[amount];
//         // vector<int> dp(amount+1, -1);
//         // return f(amount, coins, dp, 0);
//     }
// };

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(amount + 1, 0);
//         dp[0] = 1;

//         for(int j = 0; j < coins.size(); j++){
//             for(int i = coins[j]; i <= amount; ++i){
//                 dp[i] += dp[i - coins[j]];
//             }
//         }
//         return dp[amount];
//     }
// };
