class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int> st;
        st.insert(nums.begin(), nums.end());
        auto it = st.begin();
        return *it;
    }
};