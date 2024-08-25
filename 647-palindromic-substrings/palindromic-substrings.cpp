class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dfs(i, j, s)){
                    count++;
                }
            }
        }
        return count;
    }

    bool dfs(int start, int end, string& s){
        if(start > end){
            return true;
        }

        if(s[start] != s[end]) return false;

        return dfs(start+1, end-1, s);
    }
};