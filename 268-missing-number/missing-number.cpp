class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();

        // int XOR_1 =0;
        // int XOR_2 =0;

        // for(int i=0; i<n; i++)
        // {
        //     XOR_1 =XOR_1^ nums[i];
        // }

        // for(int i=0; i<=n; i++)
        // {
        //     XOR_2 = XOR_2^ i;
        // }
        // int ans = (XOR_1 ^ XOR_2);
        // return ans;

        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++)
        {
            if(nums[i] != i){
                return i;
            }
        }
        return n;
    }
};