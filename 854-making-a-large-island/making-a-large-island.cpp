class Solution {
public:
    int fun(vector<vector<int>>&v , int r , int c , vector<vector<int>>&vis , vector<pair<int,int>>&s){
        int nextR[4] = {0 , 1 , 0 , -1};
        int nextC[4] = {1 , 0 , -1 , 0};
        int n = v.size();
        int m = v[0].size();

        int ans = 0 ;

        for(int i=0 ; i<4 ; i++){
            int newR = r + nextR[i];
            int newC = c + nextC[i];

            if(newR >=0 && newR < n && newC >= 0 && newC < m && v[newR][newC] == 1 && vis[newR][newC] == 0 ){
                vis[newR][newC] = 1 ;
                s.push_back({newR , newC});
                ans += 1 + fun(v , newR , newC , vis , s);
            }
        }

        return ans ;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0 ;

        vector<vector<int>>vis(r , vector<int>(c , 0));
        vector<vector<pair<int,int>>>parent(r , vector<pair<int,int>>(c , {-1 , -1}));
        map<pair<int,int> , int>m;

        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<c ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    parent[i][j] = {i , j};
                    vis[i][j] = 1 ;
                    vector<pair<int,int>>uni ;
                    int size = 1 + fun(grid , i , j , vis , uni);
                    for(auto p : uni){
                        parent[p.first][p.second] = {i , j};
                    }
                    m[{i , j}] = size ;
                    ans = max(ans , size);
                }
            }
        }

        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<c ; j++){
                if(grid[i][j] == 0){
                    int a = 1 ;
                    set<pair<int,int>>p;
                    if(j-1 >= 0 && grid[i][j-1] == 1){
                        p.insert(parent[i][j-1]);
                    }
                    if(j+1 < c && grid[i][j+1] == 1){
                        p.insert(parent[i][j+1]);
                    }
                    if(i-1 >= 0 && grid[i-1][j] == 1){
                        p.insert(parent[i-1][j]);
                    }
                    if(i+1 < r && grid[i+1][j] == 1){
                        p.insert(parent[i+1][j]);
                    }

                    for(auto x : p){
                        a += m[x];
                    }

                    ans = max(ans , a);
                }
            }
        }

        return ans ;

    }
};