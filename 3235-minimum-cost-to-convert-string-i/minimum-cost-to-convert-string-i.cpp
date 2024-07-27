class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n= original.size();
        map<char, vector<pair<char,int>>> mpp;
        for(int i=0; i<n; i++){
            mpp[original[i]].push_back({changed[i], cost[i]});
        }
        vector<vector<int>> dp(26, vector<int>(26, -1));

        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        long long res=0;
        for(int i=0; i<source.size(); i++){
            if(source[i]==target[i]) continue;
            if(dp[source[i]-'a'][target[i]-'a'] != -1){
                res+= dp[source[i]-'a'][target[i]-'a'];
                cout<<"l";
                continue;
            }
            vector<int> dis(26, 1e8);
            pq.push({0, source[i]});
            while(!pq.empty()){
                int dist= pq.top().first;
                int node= pq.top().second;
                pq.pop();
                for(auto it: mpp[node]){
                    int wt= it.second;
                    int adjnode= it.first;
                    if(dist+wt<dis[adjnode-'a']){
                        dis[adjnode-'a']= dist+wt;
                        pq.push({dist+wt, adjnode});
                    }
                }
            }
            for(int j=0; j<26; j++){
                if(dis[j] != 1e8)
                dp[source[i]-'a'][j]= dis[j];
            }
            if(dis[target[i]-'a'] != 1e8) res+= dis[target[i]-'a'];
            else return -1;
        }
        return res;
    }
};