class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> ans;
        stack<int> st;
        st.push(nums2[m-1]);
        ans[nums2[m-1]] = -1;

        for(int i=m-2; i>=0; i--){
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            ans[nums2[i]] = (!st.empty()) ? st.top() : -1;
            st.push(nums2[i]);
        }

        vector<int> result;
        for(int i=0; i<n; i++){
            result.push_back(ans[nums1[i]]);
        }

        return result;
    }
};