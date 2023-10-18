// class Solution {
// public:
//     void helper(string &s, int ind, string &temp, vector<string> &ans){

//         if(ind == s.size()){
//             ans.push_back(temp);
//             return;
//         }
//         // if((int)s[ind] >= 48 && (int)s[ind] <= 57){
//         //     temp.push_back(s[ind]);
//         //     helper(s, ind+1, temp, ans);
//         // }

//         // else{
//         //     temp.push_back(tolower(s[ind]));
//         //     helper(s, ind+1, temp, ans);

//         //     temp.pop_back(); // Backtracking

//         //     temp.push_back(toupper(s[ind]));
//         //     helper(s, ind+1, temp, ans);        
//         // }

//         for(int i=ind; i<s.size(); i++){
//             if((int) s[i] >= 48 && (int)s[i] <= 57){
//                 temp.push_back(s[i]);
//                 continue;
//             }
//             temp.push_back(tolower(s[i]));
//             helper(s, i+1, temp, ans);
//             temp.pop_back();
//             temp.push_back(toupper(s[i]));
//             helper(s, i+1, temp, ans);
            
//         }
//     }

//     vector<string> letterCasePermutation(string s) {
//         string temp = "";
//         vector<string> ans;
//         helper(s, 0, temp, ans);
//         return ans;
//     }
// };

class Solution {
public:
    void helper(string &s, int ind, string &temp, vector<string> &ans) {
        if (ind == s.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(s[ind]);
        helper(s, ind + 1, temp, ans);
        temp.pop_back();

        if (isalpha(s[ind])) {
            if (islower(s[ind])) {
                temp.push_back(toupper(s[ind]));
            } else {
                temp.push_back(tolower(s[ind]));
            }
            helper(s, ind + 1, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        string temp = "";
        vector<string> ans;
        helper(s, 0, temp, ans);
        return ans;
    }
};