class Solution {
private:
    int f(int amount, vector<int> &coins, vector<vector<int>> &dp, int index){
        int n = coins.size();
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        if(index == n) return 0;

        if(dp[index][amount] != -1) return dp[index][amount];
        // int ans = 0;
        int ans = 0;
        // for(int i = index; i < n; ++i){
        //     ans = ans + f(amount-coins[i], coins, dp);
        // }
        amount -= coins[index];
        int pick = f(amount, coins, dp, index);

        amount += coins[index];
        int notPick = f(amount, coins, dp, index+1);
        return dp[index][amount] = (pick + notPick);
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        return f(amount, coins, dp,0);
        // dp[0] = 1; 
        // for(int i = 1; i <= amount; i++){

        //     for(int j = 0; j < coins.size(); j++){
        //         int ans = 0;
        //         if(i-coins[j] >= 0){
        //             ans = dp[i-coins[j]];
        //         }
        //         dp[i] += ans;
        //     }
        // }
        // return dp[amount];
    }   
};



// class Solution {
// public:

//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(amount + 1, 0);
//         dp[0] = 1;
        
//         for (int coin : coins) {
//             for (int i = coin; i <= amount; i++) {
//                 dp[i] += dp[i - coin];
//             }
//         }
        
//         return dp[amount];
//     }
// };
