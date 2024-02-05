class Solution {
private :
void solve(string temp, int open, int close, int n, vector<string> &ans){
    // Base Case
    if(open == n && close == n){    
        ans.push_back(temp);
    }

    // Processing
    if(open < n && open == close){
        temp.push_back('(');
        solve(temp, open + 1, close, n, ans);
    }

    else if(open < n && close < open){
        // 2 - possibilities
        // Opening
        temp.push_back('(');
        solve(temp, open + 1, close, n, ans);

        // Closing
        temp.pop_back();
        temp.push_back(')');
        solve(temp, open, close + 1, n, ans);
    }

    // Open reaches the limit --> must have to close
    else if(open == n && close < n){
        temp.push_back(')');
        solve(temp, open, close + 1, n, ans);
    }
} 

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        solve(temp, 0, 0, n, ans);
        return ans;
    }
};