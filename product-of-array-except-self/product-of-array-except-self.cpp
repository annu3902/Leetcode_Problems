class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        vector<int> prefix;
        vector<int> postfix;
        int n = nums.size();

        int pre_product = 1;
        prefix.push_back(1);

        for(int i=1; i<n; i++)
        {
            pre_product *= nums[i-1];
            prefix.push_back(pre_product);
        }

        // for(int i=0; i<n; i++){
        //     cout<<prefix[i]<<" ";
        // }
        // cout<<endl;

        int post_product = 1;
        postfix.push_back(1);

        for(int i=n-2; i>=0; i--)
        {
            post_product *= nums[i+1];
            postfix.push_back(post_product);
        }
        reverse(postfix.begin(),postfix.end());

        // for(int i=0; i<n; i++){
        //     cout<<postfix[i]<<" ";
        // }
        // cout<<endl;

        // vector<int> ans;

        for(int i=0; i<n; i++)
        {
            int result = prefix[i] * postfix[i];
            ans.push_back(result);
        }
        return ans;
    }
};