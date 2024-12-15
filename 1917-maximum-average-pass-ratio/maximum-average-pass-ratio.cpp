class Solution {
public:

    double maxAverageRatio(vector<vector<int>>& classes, int es) {
        double avgratio = 0; 
        priority_queue<pair<double, int>> pq; 
        for(int i=0; i<classes.size(); i++){
            pq.push({((double) (classes[i][0] + 1) / ((double)(classes[i][1] + 1))) - ((double) (classes[i][0]) / ((double)(classes[i][1]))), i}); 
        }
        while(es--){
            pair<double, int> top = pq.top(); 
            pq.pop(); 
            classes[top.second][0] += 1; classes[top.second][1] += 1; 
            pq.push({((double) (classes[top.second][0] + 1) / ((double)(classes[top.second][1] + 1))) - ((double) (classes[top.second][0]) / ((double)(classes[top.second][1]))), top.second}); 
        }
        while(!pq.empty()){
            pair<double, int> top = pq.top(); 
            pq.pop(); 
            avgratio += (((double)(classes[top.second][0]))/((double)(classes[top.second][1]))); 
        }
        return avgratio/classes.size(); 
    }
};