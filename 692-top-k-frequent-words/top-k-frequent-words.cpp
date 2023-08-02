class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // vector <string> ans;
        vector<string> ans;
        map<string,int> mpp;
        for(int i=0; i<words.size(); i++){
            mpp[words[i]]++;
        }

        multimap<int,string, greater<int>> mp;
        for(auto it : mpp){
            mp.insert(make_pair(it.second,it.first));
        }
        int cnt =0;
        for(auto x : mp){
            if(cnt< k){
                ans.push_back(x.second);
                cnt++;
            }
        }
        return ans;
    }
};