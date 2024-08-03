class Solution {
public:
    int countOnes(vector<int>& nums){
        int ans = 0;
        for(int i : nums){
            if(i == 1) ans++;
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        int totalOnes = countOnes(nums);
        int cntOnes = 0;
        int maxi = INT_MIN;

        while(i < n){
            if(j == n) j = j % n;
            if(nums[j] == 1){
                cntOnes++;
            }

            int length = (j >= i) ? (j-i+1) : totalOnes;
            if(length == totalOnes){
                maxi = max(maxi, cntOnes);

                if(nums[i] == 1) cntOnes--;
                i++;
            }
            else if(length > totalOnes) return 0;

            j++;

        }

        return (totalOnes - maxi);

    }
};