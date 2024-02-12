class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int maxElement;
        unordered_map<int, int> mpp;

        for(int x: nums){
            mpp[x]++;
        }

        for(pair<int, int> x : mpp){
            int element = x.first;
            int frequency = x.second;
            if(x.second > cnt){
                cnt = x.second;
                maxElement = element;
            }
        }
        return maxElement;
    }
};