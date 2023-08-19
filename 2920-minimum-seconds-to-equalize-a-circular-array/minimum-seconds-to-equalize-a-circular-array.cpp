class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> n_pos;
        int min_time = INT_MAX;

        for(int i =0; i<nums.size(); i++){
            n_pos[nums[i]].push_back(i);
        }

        for(auto &[element, pos] : n_pos){

            pos.push_back(pos[0] + nums.size());

            int seconds = 0;
            for(int i =1; i<pos.size(); i++){
                seconds = max(seconds, (pos[i] - pos[i-1])/2);
            }

            min_time = min(min_time, seconds);
        }
        return min_time;
    }
};