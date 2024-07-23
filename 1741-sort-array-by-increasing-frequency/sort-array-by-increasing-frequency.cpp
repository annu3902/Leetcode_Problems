class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i : nums){
            mp[i]++;
        }

        map<int, vector<int>> mp2;

        for(auto it : mp){

            int ele = it.first;
            int freq = it.second;

            mp2[freq].push_back(ele);
        }

        for(auto &it : mp2){
            sort(begin(it.second), end(it.second));
            reverse(begin(it.second), end(it.second));
        }

        vector<int> ans;
        for(auto it : mp2){
            vector<int> vec = it.second;
            for(int x : vec){
                int freq = it.first;
                while(freq--)
                    ans.push_back(x);
            }
        }

        return ans;
    }
};