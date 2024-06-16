class Solution {
public:
int dp[1000][1000];
    int countSubstrings(string s) {

        memset(dp, -1, sizeof(dp));

        int count = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(checkPalindrome(i, j, s)){
                    count++;
                }
            }
        }

        return count; 
    }

    bool  checkPalindrome(int start, int end, string &s){
        if(start > end) return true;

        if(dp[start][end] != -1) return dp[start][end];

        if(s[start] == s[end]){
            return dp[start][end] = checkPalindrome(start+1, end-1, s);
        }

        return false;
    }
};