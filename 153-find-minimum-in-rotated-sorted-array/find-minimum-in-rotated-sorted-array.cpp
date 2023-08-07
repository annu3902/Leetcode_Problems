// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         set<int> st(nums.begin(),nums.end());
//         // st.insert(nums.begin(), nums.end());
//         auto it = st.begin();
//         return *it;
//     }
// };

class Solution{
    public:
    int a;
    int func (vector<int>& nums, int low, int high, int mini){
        if(low > high){
            // return;
            // a = mini;
            return mini;
        }

        int mid = low + (high-low)/2;
        if(nums[low] <= nums[mid]){
            mini = min(mini,nums[low]);
           return func(nums,low+1,high,mini);
        }
        else{
            mini = min(mini, nums[mid]);
            high = mid -1;
            return func(nums,low,mid-1,mini);
        }
        // return mini;
    }

    int findMin(vector<int>& nums){
        int n =nums.size();
        // int low = 0;
        // int high = n-1;
        // int mini =INT_MAX;
        // while(low <= high){
        //     int mid = (low+high)/2;
        //     // Left Sorted
        //     if(nums[low] <= nums[mid]){
        //         mini = min(mini, nums[low]);
        //         low = mid+1;
        //     }

        //     else{
        //         mini = min(mini,nums[mid]);
        //         high = mid -1;
        //     }
        // }
        // return mini;
        // int mn = func()
        return func(nums,0,n-1,INT_MAX);
    }
};