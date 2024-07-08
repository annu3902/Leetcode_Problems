class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        // if(parent_x != parent_y){
            if(rank[parent_x] == rank[parent_y]){
                parent[parent_y] = parent_x;
                rank[parent_x]++;
            }

            else if(rank[parent_x] > rank[parent_y]){
                parent[parent_y] = parent_x;
            }

            else {
                parent[parent_x] = parent_y;
            }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n-1) return -1;

        parent.resize(n);
        iota(begin(parent), end(parent), 0);
        rank.resize(n, 0);
        int ans = n;

        for(vector<int> &connection : connections){
            int x = connection[0];
            int y = connection[1];
            if(find(x) != find(y)){
                unionSet(x, y);
                ans--;
            }
        }
        return ans-1;

        // unordered_set<int> st;
        // for(int i=0; i<n; i++){
        //     parent[i] = find(i);
        //     st.insert(parent[i]);
        // }
        
        // return st.size() - 1;
    }
};