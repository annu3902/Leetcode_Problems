class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> multiples;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                multiples.push_back(nums[i] * nums[j]);
            }
        }
        sort(multiples.begin(), multiples.end());
        int ans = 0;
        for(int i = 0; i < multiples.size(); ++i) {
            int freq = 1;
            while(i + 1 < multiples.size() && multiples[i] == multiples[i + 1]) {
                ++freq;
                ++i;
            }
            if(freq > 1) {
                ans += freq * (freq - 1);
            }
        }
        ans <<= 2;
        return ans;
    }
};