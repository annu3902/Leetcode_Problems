class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        int beauty = INT_MIN;
        map<int,int> mpp;

        for(auto x : items){
             beauty = max(beauty , x[1]);
             mpp[x[0]] = beauty;
        }

        vector<int> ans;

        for(auto x : queries){
            if(mpp.find(x) != mpp.end()){
                int bt = mpp[x];
                ans.push_back(bt);
            }
            else{
                // int y = mpp.lower_bound(x) - mpp.begin();
                auto it = mpp.lower_bound(x);
                if(it != mpp.begin()){
                    it--;
                    ans.push_back(it->second);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};