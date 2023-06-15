class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> >mpp;
        vector <vector <string> > ans;

        vector <string> temp = strs;
        for(int i=0; i<temp.size(); i++){
            string st = temp[i];
            sort(st.begin(), st.end());
            mpp[st].push_back(strs[i]);
        }

        for(map<string, vector<string> > :: iterator it =mpp.begin(); it!= mpp.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};