class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int m =nums1.size();
        int n =nums2.size();
        int i = 0;
        int j = 0;

        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }else{
                merge.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m)
        {
            merge.push_back(nums1[i]);
            i++;
        }
        
        while(j < n){
            merge.push_back(nums2[j]);
            j++;
        }

        int k =merge.size();
        
        int start = 0;
        int end = k-1;

        int mid = (start+end)/2;

        if(k % 2 != 0){
            return merge[mid];
        }

        else{
            double sum = merge[mid] + merge[mid+1];
            double ans =sum/2;
            return ans;
        }
    }
};