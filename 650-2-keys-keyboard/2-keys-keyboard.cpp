class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;

        // If n is prime then the number of operations required will be equal to n

        // Seave of Eratostenes
        vector<int> seive (n+1, true);
        for(int i = 2; i<=n; i++){
            if(i == true)
            for(int j=2; i*j <= n; j++){
                seive[i*j] = false;
            }

        }

        if(n == true) return n;

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return 1 + dfs(1, 1, n, dp);
    }

    int dfs(int copiedChar, int currA, int n, vector<vector<int>>& dp){
        if(currA > n) return 1e9;

        if(currA == n) return 0;

        if(dp[copiedChar][currA] != -1) return dp[copiedChar][currA];

        //  copy then paste
        int op1 = 2 + dfs(currA, currA + currA, n, dp);

        // direct paste
        int op2 = 1 + dfs(copiedChar, currA + copiedChar, n, dp);

        return dp[copiedChar][currA] = min(op1, op2);
    }

};