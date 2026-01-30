class Solution {
public:
    typedef pair<int, char> PA;
    typedef pair<char, int> P;
    vector<int> solve(unordered_map<char, vector<P>>& mp, char s){
        vector<int> nums(26, 1E9);
        nums[s - 'a'] = 0;

        priority_queue<PA, vector<PA>, greater<PA>> pq;
        pq.push({0, s});

        while(!pq.empty()){
            int cost = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            for(auto & neighbour : mp[c]){
                char temp = neighbour.first;
                int cst = neighbour.second;

                if(cost + cst < nums[temp - 'a']){
                    nums[temp - 'a'] = cost + cst;
                    pq.push({cost + cst, temp});
                }
            }
        }

        return nums;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        long long totalCost = 0;

        unordered_map<char, vector<P>> mp;
        for(int i=0; i<m; i++){
            mp[original[i]].push_back({changed[i], cost[i]});
        }

        unordered_map<char, vector<int>> list;

        for(int i=0; i<26; i++){
            char s = 'a' + i;
            list[s] = solve(mp, s);
        }
        
        for(int i=0; i<n; i++){
            char s = source[i];
            char d = target[i];

            if(s == d) continue;
            else if(list[s][d-'a'] == 1e9) return -1;
            else{
                totalCost += list[s][d-'a'];
            }
        }

        return totalCost;
    }
};