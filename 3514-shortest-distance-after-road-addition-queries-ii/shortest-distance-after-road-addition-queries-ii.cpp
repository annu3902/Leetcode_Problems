class Solution {
public:
    void eraseMethod(set<int>& st, int x, int y){
        auto lb = st.lower_bound(x);
        auto ub = st.upper_bound(y);

        st.erase(lb, ub);
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;

        for(int i=0; i<n; i++){
            st.insert(i);
        }

        vector<int> ans;
        for(auto query : queries){
            int u = query[0];
            int v = query[1];

            eraseMethod(st, u+1, v-1);
            ans.push_back(st.size() - 1);
        }

        return ans;
    }
};