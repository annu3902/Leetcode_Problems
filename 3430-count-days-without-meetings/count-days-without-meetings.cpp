class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> ans = mergeInterval(meetings);


        int cnt = 0;
        for(vector<int> vec : ans){
            
            cnt = cnt + (vec[1] - vec[0] + 1);

        }

        return (days - cnt);
    }

    vector<vector<int>> mergeInterval(vector<vector<int>> &meetings){

        int n = meetings.size();
        vector<vector<int>> ans;
        ans.push_back(meetings[0]);

        for(int i=1; i<n; i++){

            if(ans.back()[1] >= meetings[i][0]){
                ans.back()[1] = max(ans.back()[1], meetings[i][1]);
            }
            else{
                ans.push_back(meetings[i]);
            }
        }

        return ans;


    }
};