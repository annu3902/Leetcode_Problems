class Solution {
public:
int mod = 1e9+7;
int dp[51][101][51];
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 0, n, m, k);
    }

    int dfs(int index, int searchCost, int maxValSoFar, int n, int m, int k){
        // Base Case
        if(index == n){
            if(searchCost == k) return 1;
            else return 0;
        }

        if(dp[index][maxValSoFar][searchCost] != -1) return dp[index][maxValSoFar][searchCost];

        int result = 0;
        for(int i=1; i<=m; i++){

            if(i > maxValSoFar){
                // maxValSoFar = i;
                // searchCost++;  // This will permanently change the maxValSoFar limiting us to explore other possibility
                result = (result + dfs(index + 1, searchCost + 1, i, n, m, k)) % mod;
            }

            else{
                result = (result + dfs(index + 1, searchCost, maxValSoFar, n, m, k)) % mod;
                result %= mod;
            } 
                
        }
        return dp[index][maxValSoFar][searchCost] = result % mod;
    }
};