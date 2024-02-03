class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cnt = 0;
        int k = capacity;
        int n = plants.size();

        for(int i = 0; i < n; i++){
            if(k >= plants[i]){
                k -= plants[i];
                cnt++;
            }
            else{
                k = capacity;
                int extraStep = i*2 + 1;
                cnt += extraStep;
                k -= plants[i];
            }
        }
        return cnt;
    }
};