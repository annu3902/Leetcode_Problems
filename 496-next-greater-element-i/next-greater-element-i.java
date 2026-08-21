class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        Map<Integer, Integer> ans = new HashMap<>();

        // unordered_map<int, int> ans;
        Stack<Integer> st = new Stack<>();
        // stack<int> st;
        st.push(nums2[m-1]);
        ans.put(nums2[m-1], -1);
        // ans[nums2[m-1]] = -1;

        for(int i=m-2; i>=0; i--){
            while(!st.empty() && nums2[i] > st.peek()){
                st.pop();
            }
            if(!st.empty()){
                ans.put(nums2[i], st.peek());
            }else{
                ans.put(nums2[i], -1);
            }

            // ans.put(nums2[i]) = (!st.empty()) ? st.top() : -1;
            st.push(nums2[i]);
        }

        int[] result = new int[n];
        for(int i=0; i<n; i++){
            result[i] = (ans.get(nums1[i]));
        }

        return result;
    }
}