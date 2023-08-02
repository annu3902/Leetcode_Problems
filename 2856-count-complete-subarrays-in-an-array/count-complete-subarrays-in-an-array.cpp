class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt =0;
        set<int> st;
        int n = nums.size();
        for(int i =0; i<n; i++){
            st.insert(nums[i]);
        }

        for(int i=0; i<n; i++){
            set<int> set;
            for(int j=i; j<n; j++)
            {
                set.insert(nums[j]);
                if(set.size() == st.size()){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};