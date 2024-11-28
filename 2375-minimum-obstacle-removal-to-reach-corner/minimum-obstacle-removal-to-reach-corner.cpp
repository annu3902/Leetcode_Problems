class cmp {
    public:
        bool operator()(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
           return a.second>=b.second;
      }
};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,cmp>pq;
        int n = grid.size();
        int m = grid[0].size();
        pq.push(make_pair(make_pair(0,0),0));
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        visit[0][0]=true;
        while(!pq.empty()){
            pair<pair<int,int>,int> temp = pq.top();
            pq.pop();
            int i = temp.first.first;
            int j = temp.first.second;
            int count = temp.second;
            if(i==n-1 && j==m-1)return count;
            if(i-1>=0 && visit[i-1][j]==false){
                visit[i-1][j]=true;
                if(grid[i-1][j]==1)pq.push(make_pair(make_pair(i-1,j),count+1));
                else pq.push(make_pair(make_pair(i-1,j),count));
            }
            if(i+1<n && visit[i+1][j]==false){
                visit[i+1][j]=true;
                if(grid[i+1][j]==1)pq.push(make_pair(make_pair(i+1,j),count+1));
                else pq.push(make_pair(make_pair(i+1,j),count));
            }
            if(j-1>=0 && visit[i][j-1]==false){
                visit[i][j-1]=true;
                if(grid[i][j-1]==1)pq.push(make_pair(make_pair(i,j-1),count+1));
                else pq.push(make_pair(make_pair(i,j-1),count));
            }
            if(j+1<m && visit[i][j+1]==false){
                visit[i][j+1]=true;
                if(grid[i][j+1]==1)pq.push(make_pair(make_pair(i,j+1),count+1));
                else pq.push(make_pair(make_pair(i,j+1),count));
            }
        }
        return 0;

    }
};