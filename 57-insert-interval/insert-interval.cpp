class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};