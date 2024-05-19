class Solution {
public:
int N;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        N=n;

        vector<vector<int>> ans;
        vector<int> result;
        vector<int> visited(n, false);

        if(!visited[0]){
            dfs(0, visited, graph, result, ans);
        }
        return ans;
    }

    void dfs(int node, vector<int> &visited, vector<vector<int>> &graph, vector<int> result, vector<vector<int>> &ans){
        visited[node] = true;
        result.push_back(node);

            for(int &v : graph[node]){
                if(!visited[v]){
                    dfs(v, visited, graph, result, ans);
                }
            }
            if(result.back() == N-1){
                ans.push_back(result);
            }
            result.pop_back();
            visited[node] = false;
    }
};