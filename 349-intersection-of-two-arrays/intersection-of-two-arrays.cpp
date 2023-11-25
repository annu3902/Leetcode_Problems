class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        int n = nums1.size();
        int m = nums2.size();
        int i =0;
        // int j =0;

        // while(i<n && j<m){
        //     if(nums1[i] < nums2[j]){
        //         i++;
        //     }
        //     else if(nums2[j] < nums1[i]){
        //         j++;
        //     }
        //     else{
        //         ans.push_back(nums1[i]);
        //     }
        // }
        // return ans;
        vector<int> taken(n,0);
        for(int j =0; j<m; j++){
            for(int i =0; i<n; i++){
                if(nums2[j] == nums1[i] && taken[i] == 0){
                    ans.push_back(nums2[j]);
                }
                if(nums1[i] > nums2[j]) break;
            }
        }

        unordered_set<int> st;
        st.insert(ans.begin(), ans.end());
        vector<int> ans2;
        for(auto it : st){
            ans2.push_back(it);
        }
        return ans2;
    }
};