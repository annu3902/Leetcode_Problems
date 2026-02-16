class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>> events;
        int n = logs.size();

        for(int i=0; i<n; i++){
            int event1 = logs[i][0];
            events.push_back({event1, +1});

            int event2 = logs[i][1];
            events.push_back({event2, -1});
        }

        sort(begin(events), end(events));

        int maxPopulation = 0;
        int currPopulation = 0;
        int startYear = 0;

        for(vector<int>& event : events){
            if(event[1] == 1){
                currPopulation += 1;
                if(maxPopulation < currPopulation){
                    startYear = event[0];
                    maxPopulation = currPopulation;
                }
            }else{
                currPopulation -= 1;
            }
        }

        return startYear;
    }
};