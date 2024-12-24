
class Solution {
public:
    int calculateDiameter(const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> depth(n, -1);

        auto bfs = [&](int start) -> pair<int, int> {
            queue<int> q;
            q.push(start);
            depth[start] = 0;
            int farthestNode = start;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    if (depth[neighbor] == -1) {
                        depth[neighbor] = depth[curr] + 1;
                        q.push(neighbor);
                        farthestNode = neighbor;
                    }
                }
            }
            return {farthestNode, depth[farthestNode]};
        };

        pair<int, int> farthest1 = bfs(0);

        fill(depth.begin(), depth.end(), -1);
        pair<int, int> farthest2 = bfs(farthest1.first);

        return farthest2.second;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;

        vector<vector<int>> adj1(n1), adj2(n2);
        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int diameter1 = calculateDiameter(adj1);
        int diameter2 = calculateDiameter(adj2);

        int radius1 = (diameter1 + 1) / 2;
        int radius2 = (diameter2 + 1) / 2; 

        return max({diameter1, diameter2, radius1 + radius2 + 1});
    }
};