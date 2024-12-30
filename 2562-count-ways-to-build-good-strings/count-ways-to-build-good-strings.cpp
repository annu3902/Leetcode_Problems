class Solution {
    // Helper function for recursive approach with memoization
    int countways(int length, int low, int high, int zero, int one, vector<int>& dp) {
        if (length > high) return 0; // Base case: Exceed high, no valid strings
        
        if (dp[length] != -1) return dp[length]; // Return memoized result
        
        dp[length] = 0; // Initialize dp[length] to 0
        
        if (length >= low) dp[length] = 1; // Count this length as valid if >= low
        
        // Recursively add ways by appending zero or one
        dp[length] = (dp[length] + countways(length + zero, low, high, zero, one, dp)) % (int)(1e9 + 7);
        dp[length] = (dp[length] + countways(length + one, low, high, zero, one, dp)) % (int)(1e9 + 7);
        
        return dp[length];
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // Uncomment for recursive approach
        // vector<int> dp(high + 1, -1);
        // return countways(0, low, high, zero, one, dp);

        // Tabulation Approach
        int mod = 1e9 + 7; // Define the modulo
        vector<int> dp(high + 1, 0); // Initialize dp array
        dp[0] = 1; // Base case: One way to build an empty string

        int count = 0; // To count good strings
        for (int i = 0; i <= high; i++) {
            // Add ways to form strings by appending zero or one
            if (i - zero >= 0) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i - one >= 0) dp[i] = (dp[i] + dp[i - one]) % mod;
            
            // If the current length is valid, add to the count
            if (i >= low) count = (count + dp[i]) % mod;
        }

        return count; // Return the total count of good strings
    }
};