class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high =n-1;
        int mid;
        while(low <= high){
            int mid = (low+high)/2;
            // If target is present at the middle index
            if(nums[mid] == target){
                cout<<mid<<endl;    
                return mid;
            }

            // Check which half is sorted
            //Left Sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                    
                }
                else{
                    low = mid+1;
                }
            }
            // Right Sorted
            else{
                if(nums[mid] <= target &&target <= nums[high]){
                    low = mid+1;
                    cout<<mid<<" "<<low<<endl;
                }
                else{
                    high = mid-1;
                    cout<<mid<<" "<<high<<endl;
                }
            }
        }
        cout<<mid<<endl;
        return -1;
    }
};