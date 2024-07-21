class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        int m = rowConditions.size();
        int n = colConditions.size();

        // Creating Graph
        vector<int> rowInDegree(k+1, 0);
        unordered_map<int, vector<int>> rowAdj;
        for(vector<int> vec : rowConditions){
            int u = vec[0];
            int v = vec[1];
            rowAdj[u].push_back(v);
            rowInDegree[v]++;
        }

        vector<int> colInDegree(k+1, 0);
        unordered_map<int, vector<int>> colAdj;
        for(vector<int> vec : colConditions){
            int u = vec[0];
            int v = vec[1];
            colAdj[u].push_back(v);
            colInDegree[v]++;
        }

        vector<int> rowSort = topoSort(rowAdj, rowInDegree, k);
        // for(int i=0; i<rowSort.size(); i++){
        //     cout<<rowSort[i]<<endl;
        // }
        if(rowSort.empty()) return {};

        vector<int> colSort = topoSort(colAdj, colInDegree, k);
        if(colSort.empty()) return {};

        
        vector<vector<int>> matrix(k, vector<int> (k, 0));

        for(int i=0; i<rowSort.size(); i++){
            int element = rowSort[i];
            int j=0;

            for(; j<colSort.size(); j++){
                if(colSort[j] == element){
                    break;
                }
            }

            matrix[i][j] = element;
        }
        return matrix;

    }

    vector<int> topoSort(unordered_map<int, vector<int>>& adj, vector<int>& inDegree, int k){
        int n = inDegree.size();

        queue<int> q;
        vector<bool> visited(k+1, 0);
        vector<int> result;

        for(int i =1; i<inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
                visited[i] = true;
            }
        }

        while(!q.empty()){
            int size = q.size();
            int frontNode = q.front();
            result.push_back(frontNode);
            q.pop();

            for(auto &v : adj[frontNode]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        if(result.size() == k) return result;
        return {};
    }
};