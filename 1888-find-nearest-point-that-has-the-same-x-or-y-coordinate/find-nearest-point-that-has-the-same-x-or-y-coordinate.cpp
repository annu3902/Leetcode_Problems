class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<pair<int, int>> v;
        int n =points.size();
        int mini =INT_MAX;
        
        for(int i =0; i<n; i++)
        {
            int a = points[i][0];
            int b = points[i][1];
            if(x == a || y == b){
                mini = min(mini, abs(x-a) + abs(y-b));
                int r = i;
                int s = mini;
                v.push_back(make_pair(r,s));
            }
        }

        if(!empty(v)){
            for(int i =0; i<v.size(); i++)
            {
                if(v[i].second == mini){
                    return v[i].first;
                }
            }
        }
        return -1;
    }
};