class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end());
        int cnt=0;
        vector<int> interval=points[0];
        for(int i=1; i<n; i++){
            if(interval[1]>=points[i][0]){
                interval[0]=max(interval[0], points[i][0]);
                interval[1]=min(interval[1], points[i][1]);
            }
            else{
                cnt++;interval=points[i];
            }
        }
        return cnt+1;
    }
};