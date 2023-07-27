class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0; i<n; i++)
        {
            mpp[nums[i]]++;
        }
        multimap<int,int, greater<int>> mp;

        for(auto x : mpp){
            mp.insert(make_pair(x.second, x.first));
        }
        vector<int> v;
        // for(int i=k; i>=1; i--)
        // {
        //     v.push_back(mp[i]);
        // }
        int cnt = 0;
        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(cnt < k){
                v.push_back(it->second);
                cnt++;
            }else{
                break;
            }
        }
        return v;
    }
};