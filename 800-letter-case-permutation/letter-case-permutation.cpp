class Solution {
public:

    void helper(string &s, int ind, string &temp, vector<string> &ans){
        if(temp.size() == s.size()){
            ans.push_back(temp);
            return;
        }

        // for(int i = ind; i<s.size(); i++){

        //     if(isalpha(s[i])){
        //         temp.push_back(tolower(s[i]));
        //         helper(s, i+1, temp, ans);

        //         temp.pop_back(); // Backtracking

        //         temp.push_back(toupper(s[i]));
        //         helper(s, i+1, temp, ans);
        //         temp.pop_back();   // Backtracking
        //     }

        //     else{
        //         temp.push_back(s[i]);
        //         helper(s, i+1, temp, ans);
        //         temp.pop_back(); // Backtracking
        //     }
        // }

        if(isalpha(s[ind])){
            temp.push_back(tolower(s[ind]));
            helper(s, ind+1, temp, ans);
            temp.pop_back(); // Backtracking
            temp.push_back(toupper(s[ind]));
            helper(s, ind+1, temp, ans);
            temp.pop_back();   // Backtracking
        }

        else{
            temp.push_back(s[ind]);
            helper(s, ind+1, temp, ans);
            temp.pop_back(); // Backtracking
        }
    }


    vector<string> letterCasePermutation(string s) {
        string temp ="";
        vector<string> ans;
        helper(s, 0, temp, ans);
        return ans;
    }
};