class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()){

            int u = q.front();
            q.pop();

            for(int adj : rooms[u]){
                // for(int &v: adj){
                    if(!visited[adj]){
                        q.push(adj);
                        visited[adj] = true;
                    }
                // }
            }

        }

        for(bool x : visited){
            if(x == false) return false;
        }

        return true;

    }
};