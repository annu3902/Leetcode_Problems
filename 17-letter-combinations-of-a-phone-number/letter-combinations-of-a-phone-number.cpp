class Solution {
public:
    void helper(map<char, string> &mpp, string &digits, int ind, string &temp, vector<string> &ans){
        if(digits.size() == 0) return;
        
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return;
        }


        for(int i=ind; i<digits.size(); i++){
            string s = mpp[digits[i]];  
            for(int j=0; j<s.size(); j++){
                temp.push_back(s[j]);
                helper(mpp, digits, i+1, temp, ans);
                temp.pop_back(); // Backtracking
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char, string> mpp;
        string temp;
        vector<string> ans;
        
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz"; 

        helper(mpp, digits, 0, temp, ans);   
        return ans;    
        
    }
};