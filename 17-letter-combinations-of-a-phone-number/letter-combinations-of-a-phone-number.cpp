class Solution {
public:
    void solve(string & digits, int index, map<char, string>& mpp, string temp, vector<string> &ans){
        int n = digits.size();
        // Base Case
        if(index == n){
            if(!temp.empty())
                ans.push_back(temp);
            return;
        }

        char ch = digits[index];
        string st = mpp[ch];

        for(int i = 0; i < st.size(); i++){
            char c = st[i];
            // Include
            temp.push_back(c);
            solve(digits, index + 1, mpp, temp, ans);
            // Exclude
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        solve(digits, 0, mpp, temp, ans);
        return ans;
    }
};