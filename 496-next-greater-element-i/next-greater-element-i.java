class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int ans[] = new int[n];
        Arrays.fill(ans, -1);
        // ArrayList<Integer> arr = new ArrayList<>();

        for(int i=0; i<n; i++){
            // Find the element in nums2
            int idx = -1;
            for(int j=0; j<m; j++){
                if(nums2[j] == nums1[i]){
                    idx = j;
                    break;
                }
            }
            ans[i] = -1;

            for(int j=idx+1; j<m; j++){
                if(nums2[j] > nums2[idx]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
}