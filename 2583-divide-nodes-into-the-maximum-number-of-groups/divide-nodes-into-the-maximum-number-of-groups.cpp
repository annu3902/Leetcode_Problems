#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bfsMaxDepth(int start, vector<vector<int>>& adj, vector<int>& group) {
        queue<int> q;
        q.push(start);
        group[start] = 1;

        int maxDepth = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (group[neighbor] == -1) {
                    group[neighbor] = group[node] + 1;
                    maxDepth = max(maxDepth, group[neighbor]);
                    q.push(neighbor);
                } else if (abs(group[neighbor] - group[node]) != 1) {
                    return -1; // Graph is not bipartite
                }
            }
        }
        return maxDepth;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> group(n + 1, -1);
        vector<int> component(n + 1, -1);
        int componentId = 0;
        int result = 0;

        for (int i = 1; i <= n; ++i) {
            if (group[i] == -1) {
                queue<int> q;
                q.push(i);
                group[i] = 0;
                component[i] = componentId;

                vector<int> nodes;
                nodes.push_back(i);
                bool isBipartite = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : adj[node]) {
                        if (group[neighbor] == -1) {
                            group[neighbor] = group[node] ^ 1;
                            component[neighbor] = componentId;
                            q.push(neighbor);
                            nodes.push_back(neighbor);
                        } else if (group[neighbor] == group[node]) {
                            return -1; // Graph is not bipartite
                        }
                    }
                }

                // Find the maximum BFS depth in this component
                int maxDepth = 0;
                for (int node : nodes) {
                    vector<int> tempGroup(n + 1, -1);
                    maxDepth = max(maxDepth, bfsMaxDepth(node, adj, tempGroup));
                }

                result += maxDepth;
                componentId++;
            }
        }
        return result;
    }
};