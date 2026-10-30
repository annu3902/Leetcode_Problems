class Solution {
private:
    void dfs(int current, string temp, string digits, unordered_map<char, string> mp, vector<string>& ans){
        if(current == digits.size()){
            ans.push_back(temp);
            return;
        }

        string st = mp[digits[current]];
        for(int i=0; i<st.size(); i++){
            temp.push_back(st[i]);
            dfs(current + 1, temp, digits, mp, ans);
            temp.pop_back();
        }

        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string temp = "";
        dfs(0, temp, digits, mp, ans);

        return ans;
    }
};