class Solution {
public:

int last (vector<int>& nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            ans = mid;
            low = mid+1;
        }else if(nums[mid] < target){
            low =mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

int first (vector<int>& nums,int target){
        int low =0;
        int high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
vector<int> searchRange(vector<int>& nums, int target) {
        // if(binary_search(nums.begin(),nums.end(),target)){
        //     int start = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        //     int end = upper_bound(nums.begin(),nums.end(),target)-nums.begin() -1;
        //     return {start,end};
        // }
        // else{
        //     return{-1,-1};
        // }
        return{first(nums,target),last(nums,target)};

    }
};