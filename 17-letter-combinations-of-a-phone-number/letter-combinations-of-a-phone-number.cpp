class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> result;
        if(digits.empty()) return result;

        string temp;
        dfs(mp, 0, digits, temp, result);
        return result;
    }

    void dfs(unordered_map<char,string>& mp, int index, string& digits, string & temp, vector<string> &result){

        if(index >= digits.size()){
            result.push_back(temp);
            return;
        }

        for(auto character : mp[digits[index]]){
            temp.push_back(character);
            dfs(mp, index+1, digits, temp, result);
            temp.pop_back();
        }
    }
};