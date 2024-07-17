class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> result;

        dfs(s, 0, temp, result);
        return result;
    }

    bool isPalindrome(string s){
        int left = 0;
        int right = s.size()-1;

        while(left <= right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }

    void dfs(string s, int index, vector<string>& temp, vector<vector<string>>& result){
        if(index >= s.size()){
            result.push_back(temp);
            return;
        }

        for(int i=index; i<s.size(); i++){
            string st = s.substr(index, i-index+1);
            if(isPalindrome(st)){
                temp.push_back(st);
                dfs(s, i+1, temp, result);
                temp.pop_back();
            }
        }

    }
};