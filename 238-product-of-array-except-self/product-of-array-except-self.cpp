class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long product = 1;
        vector<long long> prefix(n, 0);
        vector<long long> suffix(n, 0);

        prefix[0] = product;
        for(int i=1; i<n; i++){
            product *= nums[i-1];
            prefix[i] = product;
            // cout<<prefix[i]<<" ";
        }

        product = 1;
        suffix[n-1] = product;

        for(int i=n-2; i>=0; i--){
            product *= nums[i+1];
            suffix[i] = product;
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(prefix[i] * suffix[i]);
        }

        return ans;
    }
};