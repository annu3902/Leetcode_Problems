class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int leftProduct = 1;
        int rightProduct = 1;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            leftProduct *= nums[i];
            rightProduct *= nums[n-i-1];

            maxi = max({maxi, leftProduct, rightProduct});

            leftProduct = (leftProduct == 0) ? 1 : leftProduct;
            rightProduct = (rightProduct == 0) ? 1 : rightProduct;
        }

        return maxi;
    }
};