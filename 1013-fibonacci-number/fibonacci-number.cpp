class Solution {
public:

    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<int> dp(n+1,-1);
        if(dp[n] != -1) return dp[n];
        return dp[n] = (fib(n-1) + fib(n-2));
    }
};