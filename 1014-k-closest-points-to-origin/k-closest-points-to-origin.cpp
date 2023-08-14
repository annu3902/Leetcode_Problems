class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans;

        //Creating a max heap
        priority_queue <pair <double, pair<int,int>>> pq;
        int n = points.size();
        // int m =points[0].size();

        for(int i =0; i<n; i++)
        {
            double x = points[i][0];
            double y = points[i][1];

            double dist = sqrt(abs(pow(x,2) + pow(y,2)));
            pq.push({dist, {points[i][0], points[i][1]}});
        }

        for(int i = 0; i <n-k; i++)
        {
            pq.pop();
        }
        // cout<<pq.size()<<endl;
        // for(int i =0; i<pq.size(); i++){
        //     for(int j =0; j<2; j++)
        //     {
        //         cout<<pq.top().second[j]<<" ";
        //     }
        //     pq.pop();
        //     cout<<endl;
        // }
        for(int i = 0; i<k; i++)
        {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            // ans.push_back(pq.top().second.first);
            pq.pop();
        }

        // vector<int> v;
        // for(int i =0 i<k; i++)
        // {
        //     for(int j =0; j<k; j++)
        //     {
        //         cout<<pq.t
        //     }
        // }
        return ans;
    }
};