class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        unordered_map<int , pair<int , int >> umap;
        for(int i = 0; i <m;i++)
        {
            for(int j = 0; j<n; j++)
            {
                umap[a[i][j]] = {i, j};
            }
        }
        // after storing all the positins of elements , 
        vector<int> row(m , n);
        vector<int> col(n ,m);
        for(int i = 0 ; i < m*n; i++)
        {
            pair<int , int > temp = umap[arr[i]];
            int r = temp.first;
            int c = temp.second;
            row[r]--;
            if(row[r]==0) return i;
            col[c]--;
            if(col[c]<=0) return i;
        }
        return m*n-1;
    }
};