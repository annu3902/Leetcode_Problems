class Solution {
public:
// int dp[1000][1000];
    int countSubstrings(string s) {
        int n = s.size();

        // memset(dp, -1, sizeof(dp));

        // int count = 0;
        // for(int i=0; i<s.size(); i++){
        //     for(int j=i; j<s.size(); j++){
        //         if(checkPalindrome(i, j, s)){
        //             count++;
        //         }
        //     }
        // }

        // return count; 


        vector<vector<bool>> dp(n, vector<bool>(n, 0));

        // dp[i][j] -> it represents weather a string starting from index i and ending to index j is a palindrome or not.
        int count = 0;

        for(int i=n-1; i >= 0; i--){

            for(int j=0; j <= n-1; j++){
                if(i >= j){
                    if(i == j) count++;
                    dp[i][j] = true;
                }

                else if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    count++;
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return count;
    }

    // bool  checkPalindrome(int start, int end, string &s){
    //     if(start > end) return true;

    //     if(dp[start][end] != -1) return dp[start][end];

    //     if(s[start] == s[end]){
    //         return dp[start][end] = checkPalindrome(start+1, end-1, s);
    //     }

    //     return dp[start][end] = false;
    // }
};