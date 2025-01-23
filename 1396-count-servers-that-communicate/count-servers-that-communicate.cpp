class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<int> rowcount(n,0);
        vector<int> colcount(m,0);

        // reachable servers
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    rowcount[i]++;
                    colcount[j]++;
                    count++;
                }
            }
        }

        // unreachable servers
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(rowcount[i] == 1 && colcount[j] == 1) count--;
                }
            }
        }
        return count;
    }
};