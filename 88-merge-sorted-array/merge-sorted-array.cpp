class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = n-1;
        int temp = m+n-1;

        while(left >= 0 && right >= 0){
            if(nums1[left] >= nums2[right]){
                nums1[temp] = nums1[left];
                temp--;
                left--;
            }

            else{
                nums1[temp] = nums2[right];
                temp--;
                right--;
            }
            
        }

        while(left >= 0){
            nums1[temp] = nums1[left];
            temp--;
            left--;
        }

        while(right >= 0){
            nums1[temp] = nums2[right];
            temp--;
            right--;
        }
    }
};