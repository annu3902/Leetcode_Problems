class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        unordered_set<int> st3;

        for(int x : nums1){
            st1.insert(x);
        }

        for(int x : nums2){
            st2.insert(x);
        }

        for(int x : st1){
            if(st2.count(x)){
                st3.insert(x);
            }
        }

        vector<int> ans;
        for(int x : st3){
            ans.push_back(x);
        }
        return ans;
    }
};