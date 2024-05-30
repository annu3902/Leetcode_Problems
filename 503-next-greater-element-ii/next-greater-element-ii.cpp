class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        stack<int> st;
        // st.push(-1);

        for(int j=n-2; j>=0; j--){
            st.push(nums[j]);
        }

        vector<int> nextElement(n, -1);

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            if(st.empty()) nextElement[i] = -1;
            else nextElement[i] = (st.top());
            
            st.push(nums[i]);

        }

        return nextElement;

    }
};