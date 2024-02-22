class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string, vector<string>> mpp;
        for(string s : strs){
            string t = s;
            sort(t.begin(), t.end());
            mpp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it : mpp){
            vector<string> temp = it.second;
            ans.push_back(temp);
        }
        return ans;
    }
};