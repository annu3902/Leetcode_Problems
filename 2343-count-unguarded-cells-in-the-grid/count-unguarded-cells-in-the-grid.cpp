class Solution {
public:
map<pair<int,int>,int>mp,mp2;
int m,n;
long cnt;
void f(int row,int col, vector<vector<bool>>&vis,int dr,int dc)
{
    if(row>=m || row<0 || col>=n || col<0)return;
    if(mp.find({row,col})!=mp.end())return;
     if(!vis[row][col])cnt++;
    vis[row][col]=true;
    f(row+dr,col+dc,vis,dr,dc);
}
    int countUnguarded(int mm, int nn, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        cnt=0;
        vector<vector<bool>>vis(mm,vector<bool>(nn,false));
      for(auto it:walls)
      {
        vis[it[0]][it[1]]=true;
        mp[{it[0],it[1]}]++;
        cnt++;
      }  

      m=mm;
      n=nn; 
      for(auto it:guards)
      {
         mp[{it[0],it[1]}]++;
        vis[it[0]][it[1]]=true;
        cnt++;
      }
      for(auto it:guards)
      {
        f(it[0]+1,it[1]-0,vis,1,0);
        f(it[0]-1,it[1]+0,vis,-1,0);
        f(it[0],it[1]+1,vis,0,1);
        f(it[0],it[1]-1,vis,0,-1);
      }
       long a=m*n;
      int ans=a-cnt;
      return ans;

    }
};