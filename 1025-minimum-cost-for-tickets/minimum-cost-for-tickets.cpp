class Solution {
public:
    int find(int i, vector<int>& days, vector<int>& costs, vector<int>& dp, vector<int>& index) {
        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        // Choose a 1-day pass, then recursively solve for the next day
        int a = costs[0] + find(i + 1, days, costs, dp, index);

        // Choose a 7-day pass, skip to the next day covered by the pass
        a = min(a, costs[1] + find(index[days[i] + 6], days, costs, dp, index));

        // Choose a 30-day pass, skip to the next day covered by the pass
        a = min(a, costs[2] + find(index[days[i] + 29], days, costs, dp, index));

        return dp[i] = a; // Memoize the result
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1); // Initialize dp array
        vector<int> lol(450, n); // Initialize index array

        int j = 0;
        for (int i = 1; i < days[n - 1] + 1; i++) {
            if (days[j] <= i) {
                j++; // Update the index for the next travel day
            }
            lol[i] = j; // Store the index of the next travel day
        }

        int ans = find(0, days, costs, dp, lol); // Start from the first day
        return ans; // Return the minimum cost
    }
};