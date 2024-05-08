class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<int> vec = score;

        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());

        unordered_map<int, int> mp;
        for(int i=0; i<vec.size(); i++){
            mp[vec[i]] = i+1;
        }

        for(int i=0; i<score.size(); i++){
            int pos = mp[score[i]];
            if(pos == 1) ans.push_back("Gold Medal");
            else if(pos == 2) ans.push_back("Silver Medal");
            else if(pos == 3) ans.push_back("Bronze Medal");
            else{
                ans.push_back(to_string(pos));
            }
        }
        return ans;
    }
};