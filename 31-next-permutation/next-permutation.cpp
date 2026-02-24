class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        bool flag = true;
        int k = -1;
        for(int i = n-2; i >= 0; i--){
            int curr = nums[i];
            int prev = nums[i+1];
            if(curr < prev){
                flag = false;
                k = i + 1;
                break;
            }
        }

        if(!flag){
            for(int i = n-1; i >= k; i--){
                if(nums[i] > nums[k-1]){
                    swap(nums[k-1], nums[i]);
                    break;
                }
            }

            sort(nums.begin() + k, nums.end());
        }

        if(flag == true){
            reverse(begin(nums), end(nums));
        }
    }
};