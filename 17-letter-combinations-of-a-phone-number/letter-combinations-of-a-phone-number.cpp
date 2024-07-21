class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
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
        string temp ="";
        solve(0, digits, temp, mp, ans);

        return ans;
    }

    void solve(int index, string &s, string &temp, unordered_map<char, string>& mp, vector<string> &ans){

        if(index >= s.size()){
           ans.push_back(temp);
           return;
        }

        for(char c : mp[s[index]]){
            temp.push_back(c);
            solve(index+1, s, temp, mp, ans);
            temp.pop_back();
        }

    }
};