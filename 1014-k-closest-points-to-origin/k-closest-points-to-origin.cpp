class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans;

        //Creating a max heap
        priority_queue <pair <double, pair<int,int>>> pq;
        int n = points.size();

        for(int i =0; i<n; i++)
        {
            double x = points[i][0];
            double y = points[i][1];

            pq.push({sqrt(pow(x,2) + pow(y,2)), {points[i][0], points[i][1]}});
        }

        for(int i = 0; i <n-k; i++)
        {
            pq.pop();
        }
  
        for(int i = 0; i<k; i++)
        {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }

        return ans;
    }
};