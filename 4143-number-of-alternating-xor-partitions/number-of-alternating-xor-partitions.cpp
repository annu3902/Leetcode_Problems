class Solution {
public:
    long long mod = 1e9+7;
    int alternatingXOR(vector<int>& nums, int t1, int t2){
        int n = nums.size();

        long long px=0;
        // dp1[i] -> No of valid partitions ending at index i having last block as t1;
        // dp2[i] -> No of valid parititions ending at index i having last block as t2
        vector<long long> dp1(n, 0);
        vector<long long> dp2(n, 0);
        unordered_map<long long, long long> cnt1;
        unordered_map<long long, long long> cnt2;

        for(int i=0; i<n; i++){

            px = px^nums[i];

            if(px == t1){
                dp1[i] = 1;
            }
            dp1[i] = (dp1[i] + cnt2[px ^ t1]) % mod;
            dp2[i] = (dp2[i] + cnt1[px ^ t2]) % mod;

            cnt1[px] = (cnt1[px] + dp1[i]) % mod;
            cnt2[px] = (cnt2[px] + dp2[i]) % mod;
        }
        return (dp1[n-1] + dp2[n-1]) % mod;

        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            px = px^nums[i];

            if(px == t1){
                dp1[i] = 1;
            }
            dp1[i] = dp1[i];
            // cnt2[px ^ t1] = dp2[j-1] + dp2[j-2] + dp2[j-3] + ...
            for(auto it: mp){
                int t5 = it.first ^ px;
                vector<int> loc = it.second;
                for(int j=0; j<loc.size(); j++){
                    dp1[i] = (dp1[i] + dp2[j]) % mod;
                }
            }

            dp2[i] = dp2[i];
            for(auto it : mp){
                int t4 = it.first ^ px;
                vector<int> loc = it.second;
                for(int k=0; k<loc.size(); k++){
                    dp2[i] = (dp2[i] + dp1[k]) % mod;
                }
            }
            mp[px].push_back(i);
            // cnt1[px ^ t2] = dp1[k-1] + dp1[k-2] + ...

            // cnt1[px] = cnt1[px] + dp1[i];
            // cnt2[px] = cnt[px] + dp2[i];
        }
    }


};