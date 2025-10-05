class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int n = intervals.size();
        if(n == 1) return intervals;

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i+1;

            while(j < n){
                int start1 = intervals[j][0];
                int end1 = intervals[j][1];

                if(end >= start1 ){
                    if(end <= end1)
                        end = end1;
                }
                else{
                    break;
                }
                j++;
            }
            ans.push_back({start, end});
            i = j-1;

        }

        return ans;
    }
};