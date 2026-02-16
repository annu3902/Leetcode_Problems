class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1; i < n; i++){
            if(end >= intervals[i][0]){
                end = max(end, intervals[i][1]);
                start = min(start, intervals[i][0]);
            }else{
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start, end});

        return result;
    }
};