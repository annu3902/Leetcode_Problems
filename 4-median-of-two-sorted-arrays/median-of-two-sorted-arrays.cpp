class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = 0;

        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }else {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m){
            nums.push_back(nums1[i]);
            i++;
        }

        while(j < n){
            nums.push_back(nums2[j]);
            j++;
        }

        int k = nums.size();

        if((nums.size() & 1) == 0) return (double)(nums[k/2] + nums[(k / 2 - 1)])/2;
        else return nums[k / 2];
    }
};