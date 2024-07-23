class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }

        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for(auto it : mp){
            int ele = it.first;
            int freq = it.second;

            pq.push({-freq, ele});
        }

        while(!pq.empty()){

            int freq = -pq.top().first;
            int ele = pq.top().second;

            while(freq--){
                ans.push_back(ele);
            }
            pq.pop();
        }

        return ans;
    }
};