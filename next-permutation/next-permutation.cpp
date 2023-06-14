class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.empty()){
            // return;
        }

        int n =nums.size();
        int index =-1;

        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1)
        {
            sort(nums.begin(), nums.end());
            return;
            // reverse(nums.begin(), nums.end());
        }

        for(int i =n-1; i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        int start = index +1;
        int end = n-1;

        while(start <= end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         int index = -1;

//         for(int i = n - 2; i >= 0 && index == -1; i--) {
//             if(nums[i] < nums[i+1]) {
//                 index = i;
//             }
//         }

//         if(index == -1) {
//             sort(nums.begin(), nums.end());
//             return;
//         }

//         for(int i = n - 1; i > index; i--) {
//             if(nums[i] > nums[index]) {
//                 swap(nums[i], nums[index]);
//                 break;
//             }
//         }

//         int start = index + 1;
//         int end = n - 1;

//         while(start <= end) {
//             swap(nums[start], nums[end]);
//             start++;
//             end--;
//         }
//     }
// };