class Solution {
public:
    vector<int> hours = {1, 2, 4, 8};
    vector<int> minutes = {1, 2, 4, 8, 16, 32};
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn == 0){
            return {"0:00"};
        }
        else if(turnedOn >= 9){
            return {};
        }

        vector<string> result;

        solve(turnedOn, 0, {0,0}, result);

        return result;
    }

    void solve(int turnedOn, int startPoint, pair<int, int> time, vector<string>& result){

        if(turnedOn == 0){
            if(time.first <= 11 && time.second <= 59)
            result.push_back(to_string(time.first) + ((time.second < 10) ? ":0" : ":") + to_string(time.second));
            return;
        }

        for(int i=startPoint; i<10; i++){  
            if(i < 4){
                time.first += hours[i];
                 solve(turnedOn-1, i+1, time, result);
                time.first -= hours[i];
            }

            else{
                time.second += minutes[i - 4];
                solve(turnedOn-1, i+1, time, result);
                time.second -= minutes[i - 4];
            }
        }
        return;
    }
};