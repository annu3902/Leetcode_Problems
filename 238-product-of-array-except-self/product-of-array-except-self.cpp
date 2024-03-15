class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix;
        vector<int> suffix;
        int product=1;
        prefix.push_back(product);
        suffix.push_back(product);

        for(int i=1; i<n; i++){
            product *= nums[i-1];
            prefix.push_back(product);
        }
        // for(int x : prefix) cout<<x<<" ";
        product=1;
        for(int j=n-2; j>=0; j--){
            product *= nums[j+1];
            suffix.push_back(product);
        }


        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(prefix[i]*suffix[n-i-1]);
        }
        return ans;
        // return nums;

    }
};