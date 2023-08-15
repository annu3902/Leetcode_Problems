// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

//         int n = items.size();
//         int q = queries.size();


//         map<int,vector<int>>m;
//         for(int i=0;i<n;i++){
//             m[items[i][0]].push_back(items[i][1]);
//         }        


//         vector<int> ans;
//         int x = m.size();
//         vector<int>dp(x+1,-1);
//         int k = 0;
//         for(int i=0;i<q;i++){
//             int maxi = INT_MIN;
//             k = 0;
//             for(auto it:m){
//                 if(dp[k]!=-1){
//                     maxi = dp[k++];
//                 }
//                 else{
//                     if(it.first<=queries[i]){
//                         for(int j=0;j<it.second.size();j++){
//                             maxi = max(maxi , it.second[j]);
//                         }
//                         dp[k++] = maxi;
//                     }
//                 }
//             }
//             if(maxi == INT_MIN) maxi = 0;
//             ans.push_back(maxi);
//         }
//         return ans;
//     }
// };

class Solution {
public:

    static bool mycmp(vector<int> &a , vector<int> &b){
        return a[0]<b[0];
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        sort(items.begin() , items.end() , mycmp);

        map<int , int> mp;

        int bt = INT_MIN;

        for(auto x:items){
            bt = max(bt , x[1]);
            mp[x[0]] = bt;
        }

        int n = queries.size();
        vector<int> ans(n);

        for(int i = 0 ; i<n ; i++){
            
            if(mp.count(queries[i])){
                ans[i] = mp[queries[i]];
            }else{

                auto x = mp.lower_bound(queries[i]);

                if(x == mp.begin())
                ans[i] =0;
                else{
                    x--;
                    ans[i] = x->second;
                }
            }   
        }

        return ans;

    }
};