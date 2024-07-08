class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(rank[parent_x] == rank[parent_y]){
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
        else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }

        else{
            parent[parent_x] = parent_y;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        int connection = edges.size();
        parent.resize(n);
        iota(begin(parent), end(parent), 0);
        rank.resize(n, 0);
        
        int components = n;
        for(vector<int> edge : edges){
            int x = edge[0];
            int y = edge[1];

            if(find(x) != find(y)){
                unionSet(x, y);
                components--;
            }
        }

        for(int i=0; i<n; i++){
            parent[i] = find(i);
        }

        map<int, int> mp;
        for(int & freq : parent){
            mp[freq]++;
        }

        vector<long long> nums;

        for(auto it : mp){
            nums.push_back(it.second);
        }

    long long sum = 0;
    long long sumOfSquares = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        sumOfSquares += nums[i] * nums[i];
    }

    long long totalSum = (sum * sum - sumOfSquares) / 2;

    return totalSum;

    }
};