class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);
        // cout<<n<<" ";

        int targetArrivalTime = times[targetFriend][0]; // Since the arrival time of every friend are distinct each friend will have unique arrival time
        cout<<targetArrivalTime<<" "<<endl;

        sort(begin(times), end(times));
        for(vector<int> &vec : times){
            cout<<vec[0]<<" "<<vec[1]<<endl;
        }

        for(int i=0; i<n; i++){
            int arrivalTime = times[i][0];
            int departureTime = times[i][1];

            int j = 0;
            // while(j < n){
            //     if(chairs[j] == -1 || chairs[j] == arrivalTime){
            //         chairs[j] = departureTime;
            //         break;
            //     }
            //     j++;
            // }
            for(; j<n; j++){
                if(chairs[j] == -1 || chairs[j] <= arrivalTime){
                    chairs[j] = departureTime;
                    break;
                } 
            }

            if(arrivalTime == targetArrivalTime){
                return j;
            }
        }

        return -1;        
    }
};




























        // map<int, int> mp;
        // int friendNo = 0;
        // for(vector<int> &vec : times){
        //     int arrivalTime = vec[0];
        //     mp[arrivalTime] = friendNo;
        //     friendNo++;
        // }

        // unordered_map<int, int> chairMap; // {chair - friend}
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // // {departure time -> friend}

        // int chairAllocate = 0;  

        // for(auto& it : mp){
        //     int arrivalTime = it.first;
        //     int friendNo = it.second;
        //     int departureTime = times[friendNo][1];

        //     minHeap.push({departureTime, friendNo});

        // }