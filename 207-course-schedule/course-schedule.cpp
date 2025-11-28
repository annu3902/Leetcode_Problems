class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);

        for(vector<int>& prerequisite : prerequisites){
            int first = prerequisite[1];
            int second = prerequisite[0];

            adj[first].push_back(second);
            inDegree[second]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            
            int course = q.front();
            q.pop();
            for(auto &v : adj[course]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
            count++;

        }

        if(count != numCourses) return false;

        return true;

    }
};