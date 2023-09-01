class Solution {
public:

    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<int> dp(n+1,-1);

        int partialans_1 = fib(n-1);
        int partialans_2 = fib(n-2);
        return dp[n] = (partialans_1 + partialans_2);
    }
};