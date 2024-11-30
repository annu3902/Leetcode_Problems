class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        map<int, int>indeg, outdeg;
        map<int, vector<int>>adj;
        for(int i = 0; i<n; i++){
            int x = pairs[i][0];
            int y = pairs[i][1];
            adj[x].push_back(y);
            outdeg[x]++;
            indeg[y]++;
        }
        map<pair<int,int>, int>used;
        vector<vector<int>>ans;
        function<void(int)>dfs = [&](int node){
            
                while(!adj[node].empty()){
                    int j=adj[node].back();
                    adj[node].pop_back();
                    dfs(j);
                    ans.push_back({node, j});
                }
            
        };

        bool flag = 0;
        for(auto j:outdeg){
            if((outdeg[j.first]-indeg[j.first]) >= 0 && (outdeg[j.first]-indeg[j.first]) % 2 == 1){
                dfs(j.first);
                flag = 1;
                break;
            }
        }
        if(!flag){
            for(auto j:outdeg){
                dfs(j.first);
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};