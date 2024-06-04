class Solution {
public:
    int n;
    int dp[1001][1001];

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(dp, -1, sizeof(dp));

        return solve(pairs, 0, -1);
        
        // vector<int> dp(n, 1); // dp[i] => Length of longest increasing subsequence ending at index i

        // for(int i=1; i<n; i++){
        //     for(int j=0; j<i; j++){
        //         if(pairs[j][1] < pairs[i][0]){
        //             dp[i] = max(1 + dp[j], dp[i]);
        //         }
        //     }
        // }

        // return *max_element(dp.begin(), dp.end());
    }

    int solve(vector<vector<int>> &pairs, int currIndex, int prevIndex){

        if(currIndex == pairs.size()) return 0;

        if(prevIndex != -1 && dp[currIndex][prevIndex] != -1) return dp[currIndex][prevIndex];

        int skip = solve(pairs, currIndex+1, prevIndex);

        int pick = 0;

        if(prevIndex == -1 || pairs[currIndex][0] > pairs[prevIndex][1]){
            pick = 1 + solve(pairs, currIndex+1, currIndex);
        }

        if(prevIndex != -1) dp[currIndex][prevIndex] = max(skip, pick);

        return  max(skip, pick);
    }
};