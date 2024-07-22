class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({heights[i], names[i]});
        }

        vector<string > ans;

        sort(begin(vec), end(vec));
        reverse(begin(vec), end(vec));
        for(auto p : vec){
            ans.push_back(p.second);
        }

        return ans;
    }
};