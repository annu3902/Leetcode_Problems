class Solution {
public:
    int findMin(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        // st.insert(nums.begin(), nums.end());
        auto it = st.begin();
        return *it;
    }
};