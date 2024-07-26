class Solution {
public:
    void dfs(int i, int n, int distanceThreshold, map<int, vector<pair<int, int>>>& mp, set<int>& visited, map<int, int>& distances, int currentDistance) {
        visited.insert(i);
        for (const auto& ng : mp[i]) {
            int next = ng.first;
            int dis = ng.second;
            if (currentDistance + dis <= distanceThreshold && (distances.find(next) == distances.end() || currentDistance + dis < distances[next])) {
                distances[next] = currentDistance + dis;
                dfs(next, n, distanceThreshold, mp, visited, distances, currentDistance + dis);
            }
        }
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        map<int, vector<pair<int, int>>> mp;
        for (const auto& e : edges) {
            mp[e[0]].emplace_back(e[1], e[2]);
            mp[e[1]].emplace_back(e[0], e[2]);
        }
        
        int res = -1;
        int min_neigh = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            set<int> visited;
            map<int, int> distances;
            dfs(i, n, distanceThreshold, mp, visited, distances, 0);
            
            int neigh = visited.size() - 1;
            if (neigh <= min_neigh) {
                res = i;
                min_neigh = neigh;
            }
        }
        
        return res;
    }
};