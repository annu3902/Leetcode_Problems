class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans;

        //Creating a max heap
        priority_queue <pair <double, vector<int>>> pq;
        int n = points.size();
        // int m =points[0].size();

        for(int i =0; i<n; i++)
        {
            double x = points[i][0];
            double y = points[i][1];

            double dist = sqrt(abs(pow(x,2) + pow(y,2)));
            pq.push(make_pair(dist, points[i]));
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
            ans.push_back(pq.top().second);
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