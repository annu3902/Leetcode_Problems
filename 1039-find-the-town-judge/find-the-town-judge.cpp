class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // conditions to satisfy
        // 1. Town judge trust no-one
        // 2. Everyone trust town judge

        // Solving using outdegree and indegree count
        vector<int> out(n+1,0);
        vector<int> in(n+1,0);

        for(vector<int> x : trust){
            out[x[0]]++;
            in[x[1]]++;
        }

        for(int i=1; i<=n; i++){
            if(out[i]==0 && in[i]==n-1) return i;
        }
        return -1;
    }
};