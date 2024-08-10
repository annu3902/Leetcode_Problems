class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
      int n=grid.front().size();
      for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
          fill(b[i][j],b[i][j]+4,0);
          if (grid[i][j]=='/'){
            g[i][j][0].push_back({{i,j},1});
            g[i][j][1].push_back({{i,j},0});
            g[i][j][2].push_back({{i,j},3});
            g[i][j][3].push_back({{i,j},2});
          }else if (grid[i][j]=='\\'){
            g[i][j][0].push_back({{i,j},3});
            g[i][j][1].push_back({{i,j},2});
            g[i][j][2].push_back({{i,j},1});
            g[i][j][3].push_back({{i,j},0});
          }else {
            g[i][j][0].push_back({{i,j},1});
            g[i][j][0].push_back({{i,j},2});
            g[i][j][0].push_back({{i,j},3});
            g[i][j][1].push_back({{i,j},0});
            g[i][j][2].push_back({{i,j},0});
            g[i][j][3].push_back({{i,j},0});
          } 
        }
      }
      for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
          g[i][j][3].push_back({{i,j+1},1});
          g[i][j+1][1].push_back({{i,j},3});
        }
      }
      for (int i=0; i<n-1; i++){
        for (int j=0; j<n; j++){
          g[i][j][2].push_back({{i+1,j},0});
          g[i+1][j][0].push_back({{i,j},2});
        }
      }
      int numComp=0;
      for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
          for (int k=0; k<4; k++){
            if (b[i][j][k]==0){
              b[i][j][k]=1;
              numComp++;
              dfs(i,j,k);
            }
          }
        }
      }
      return numComp;
    }
private:
  vector <pair<pair<int,int> , int> > g[30][30][4];
  bool b[30][30][4];
  void dfs(int i,int j,int k){
    for (int ed=0; ed<g[i][j][k].size(); ed++){
      int ii=g[i][j][k][ed].first.first;
      int jj=g[i][j][k][ed].first.second;
      int kk=g[i][j][k][ed].second;
      if (b[ii][jj][kk]==0){
        b[ii][jj][kk]=1;
        dfs(ii,jj,kk);
      }
    }
    return ;
  }
};