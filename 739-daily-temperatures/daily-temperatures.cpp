class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(n - 1);

        for(int i = n - 2; i >= 0; i--){

            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }

            if(!st.empty() && nums[i] < nums[st.top()]){
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;

    }
};