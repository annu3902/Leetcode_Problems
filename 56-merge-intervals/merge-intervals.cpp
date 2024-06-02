class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;

        // BRUTE FORCE
        // for(int i=0; i<n; i++){
            
        //     if(!result.empty()){
        //         if(result.back()[1] >= intervals[i][0])
        //             continue;
        //     }

        //     vector<int> temp = intervals[i];
        //     for(int j=i+1; j<n; j++){

        //         if(intervals[j][0] <= temp[1]){
        //             temp[1] = max(temp[1], intervals[j][1]);
        //         }

        //         else{
        //             break;
        //         }


        //     }

        //     result.push_back(temp);

        // }

        // OPTIMAL Solution
        vector<int> temp = intervals[0];

        for(int i=1; i<n; i++){

            if(intervals[i][0] <= temp.back()){
                temp.back() = max(temp.back(), intervals[i][1]);
            }
            else{
                result.push_back(temp);
                temp = intervals[i];
            }
        }

        result.push_back(temp);

        return result;

    }
};