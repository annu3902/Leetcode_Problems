class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
    
        while(i<n&&j<m){
            if(nums1[i]<nums2[j]) i++;
            else if(nums2[j]<nums1[i]) j++;
            else return nums1[i];
        }
        return -1;
    }
};