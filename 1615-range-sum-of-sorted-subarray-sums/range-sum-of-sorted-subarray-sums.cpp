class Solution {
public:
int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                ans.push_back(sum);
            }
        }

        sort(begin(ans), end(ans));

        int totalSum = 0;
        for(int i=left-1; i<right; i++){
            totalSum = (totalSum + ans[i]) % MOD;
        }

        return totalSum;
    }
};