class Solution {
public:
typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pi> pq;

        unordered_map<int, int>mp;
        for(int num : nums){
            mp[num]++;
        }

        for(auto it : mp){
            int num = it.first;
            int freq = it.second;

            pq.push({freq, num});
        }

        vector<int> result;
        while(k){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};