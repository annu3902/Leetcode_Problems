class Solution {
public:
    int t[1001][1001];
    int solve(string &text1, int i, int j, string& text2){

        if(i >= text1.size() && j >= text2.size()) return 0;
        else if(i >= text1.size() && j < text2.size()) return 0;
        else if(i < text1.size() && j >= text2.size()) return 0;

        else if(t[i][j] != -1) return t[i][j];

        if(text1[i] == text2[j]){
            return 1 + solve(text1, i+1, j+1, text2);
        }
        
        int op1 = solve(text1, i+1, j, text2);
        int op2 = solve(text1, i, j+1, text2);

        return t[i][j] = max(op1, op2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        memset(t, 0, sizeof(t));
        for(int j=0; j<n; j++) t[0][j] = 0;
        for(int i=0; i<m; i++) t[i][0] = 0;
        // return solve(text1, 0, 0, text2);
        // t[i][j] -> Length of longest common subsequence ending at index i,j
        for(int i=1; i<=m; i++){

            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }

        }

        return t[m][n];

    }
};