class Solution {
public:
    // Brute Force
    // int arithmeticTriplets(vector<int>& nums, int diff) {
    //     int n = nums.size();
    //     int cnt = 0;

    //     for(int i = 0; i < n - 2; i++){
    //         for(int j = i + 1; j < n - 1; j++){
    //             vector<int> temp;
    //             for(int k = j + 1; k < n; k++){
    //                 if((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff)){
    //                     temp.push_back(nums[i]);
    //                     temp.push_back(nums[j]);
    //                     temp.push_back(nums[k]);
    //                     cnt++;
    //                     break;
    //                 }
    //             }
    //             for(int x : temp) cout<<x<<" ";
    //             cout<<endl;
    //         }
    //     }
    //     return cnt;
    // }

    int arithmeticTriplets(vector<int>& nums, int diff){
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n - 2; i++){
            int left = i + 1;
            int right = n - 1;

            while(left < right){
                if(nums[left] - nums[i] > diff){
                    break;
                }
                if(nums[right] - nums[left] < diff){
                    break;
                }
                else if(nums[left] - nums[i] < diff){
                    left++;
                    continue;
                }
                else if(nums[right] - nums[left] > diff){
                    right--;
                    continue;
                }

                // else if((nums[left] - nums[i] == diff) && (nums[right] - nums[left] == diff)){
                //     cnt++;
                //     break;
                // }
                else{
                    cnt++;
                    break;
                }
                // left++;
            }
        }
        return cnt;
    }
};