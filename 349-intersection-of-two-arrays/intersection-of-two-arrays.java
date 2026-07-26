class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> ans = new ArrayList<>();
        int n = nums1.length;
        int m = nums2.length;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else if(!ans.contains(nums1[i])){
                ans.add(nums1[i]);
                i++;
                j++;
            }else{
                i++;
                j++;
            }
        }

        int[] result = new int[ans.size()];
        for (int k = 0; k < ans.size(); k++) {
            result[k] = ans.get(k);
        }
        return result;
    }
}