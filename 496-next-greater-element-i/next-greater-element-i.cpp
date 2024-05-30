class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;

        stack<int> st;
        st.push(-1);
        unordered_map<int, int> nextElement;

        for(int j=nums2.size()-1; j>=0; j--){

            while(!st.empty() && st.top() <= nums2[j] && st.top() != -1){
                st.pop();
            }

            nextElement[nums2[j]] = st.top();
            st.push(nums2[j]);
        }

        for(int i=0; i<nums1.size(); i++){
            ans.push_back(nextElement[nums1[i]]);
        }

        return ans;
    }
};