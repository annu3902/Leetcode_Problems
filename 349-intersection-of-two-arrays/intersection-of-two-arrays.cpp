class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set<int> st1;
        // unordered_set<int> st2;
        // unordered_set<int> st3;

        // for(int x : nums1){
        //     st1.insert(x);
        // }

        // for(int x : nums2){
        //     st2.insert(x);
        // }

        // for(int x : st1){
        //     if(st2.count(x)){
        //         st3.insert(x);
        //     }
        // }

        // vector<int> ans;
        // for(int x : st3){
        //     ans.push_back(x);
        // }
        // return ans;


        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(), nums2.end());
        // unordered_set<int> st;
        // int i, j =0;

        // while(i < nums1.size() && j < nums2.size()){
        //     if(nums1[i] < nums2[j]) i++;
        //     else if(nums2[j] < nums1[i]) j++;
        //     else{
        //         if(st.find(nums1[i]) == st.end()){
        //             st.insert(nums1[i]);
        //         }
        //         i++;
        //         j++;
        //     }
        // }
        // for(auto x: st){
        //     cout<<x<<" ";
        // }
        // vector<int>ans; 

        // for(int x : st){
        //     ans.push_back(x);
        // }
        // return ans;

        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            vector<int> :: iterator it;
            it = find(nums2.begin(), nums2.end(),nums1[i]);
            if(it!=nums2.end()){
                if(find(v.begin(),v.end(),nums1[i])==v.end()) v.push_back(nums1[i]);
            }
        }

        for(int i=0;i<nums2.size();i++){
            vector<int> :: iterator it;
            it = find(nums1.begin(), nums1.end(),nums2[i]);
            if(it!=nums1.end()){
                if(find(v.begin(),v.end(),nums2[i])==v.end()) v.push_back(nums2[i]);
            }
        }

        return v;
    }
};