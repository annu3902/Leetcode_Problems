class Solution {
public:
    double maxProbability(int n, 
                          vector<vector<int>>& edges, 
                          vector<double>& succProb, 
                          int start_node, 
                          int end_node) {

        // 1. Initialize a adjacency list to represent the 
        // connected nodes for easier traversal of neighbours and 
        // the probabilities to move to them.
        vector<vector<pair<int, double>>> g(n);
        // Build the graph
        for (int i=0; i<edges.size(); i++) {
            double s = succProb[i];
            int a = edges[i][0], b = edges[i][1];
            g[a].push_back({b, s});
            g[b].push_back({a, s});
        }

        // 2. Initialize an array p of size n representing the 
        // probability to reach each node from start_node.
        vector<double> p(n);

        // 3. Start Bread-First Traversal from the start_node 
        // with probability = 1.0.
        p[start_node] = 1.0;
        queue<pair<double, int>> q;

        // 3.1 Offer start_node with probability 1.0 to the BFS queue.
        q.push({1.0, start_node});

        while (!q.empty()) {
            auto c = q.front(); q.pop();
            int u = c.second;
            double w = c.first;

            // 3.2 For each node (lets call it u) in the queue, if the 
            // offered probability is less than the node's current 
            // probability; then skip visiting the current node.
            if (p[u] > w) continue;

            // 3.3 Otherwise, traverse each neighbouring node 
            // (lets call it v) and update their probabilities.
            for (auto& n: g[u]) {
                int v = n.first;
                double W_uv = n.second;

                // 3.3.1 If the probability to reach node v decreases 
                // by visiting it via node u, then update it.
                if (p[v] < p[u] * W_uv) {
                    p[v] = p[u] * W_uv;
                    
                    // 3.3.2 Push the updated node to the queue to
                    // re-visit its neighbours.
                    q.push({p[v], v});
                }
            }
        }

        // 4. Return p[end_node] as it is the final probability after 
        // there are no more updates.
        return p[end_node];
    }
};