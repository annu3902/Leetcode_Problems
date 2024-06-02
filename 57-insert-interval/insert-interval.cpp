class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        mergeIntervals(intervals, result);
        return result;
    }

    void mergeIntervals(vector<vector<int>> &intervals, vector<vector<int>> &result){

        vector<int> temp = intervals[0];

        for(int i=1; i<intervals.size(); i++){

            if(intervals[i][0] <= temp.back()){
                temp.back() = max(temp.back(), intervals[i][1]);
            }
            else{
                result.push_back(temp);
                temp = intervals[i];
            }

        }

        result.push_back(temp);

    }
};