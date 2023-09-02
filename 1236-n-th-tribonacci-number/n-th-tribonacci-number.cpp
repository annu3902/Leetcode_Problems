class Solution {
public:

    int tribo(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        // vector<int> dp(n+1, -1);
        if(dp[n] != -1) return dp[n];
        int p1 = tribo(n-1, dp);
        int p2 = tribo(n-2, dp);
        int p3 = tribo(n-3, dp);


        return dp[n] = p1 + p2 + p3;
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return tribo(n, dp);
    }
};