class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ls1;
        vector<int> ls2;
        vector<vector<int>> ans;
        vector<int> :: iterator it1;
        vector<int> :: iterator it2;
        vector<int> :: iterator it3;
        vector<int> :: iterator it4;

        for(int i =0; i<nums1.size(); i++){
            it1 = find(nums2.begin(), nums2.end(), nums1[i]);
            if(it1 == nums2.end()){
                it3 = find(ls1.begin(), ls1.end(), nums1[i]);
                if(it3 == ls1.end())
                    ls1.push_back(nums1[i]);
            }
        }

        for(int i=0; i<nums2.size(); i++){
            it2 = find(nums1.begin(), nums1.end(), nums2[i]);
            if(it2 == nums1.end()){
                it4 = find(ls2.begin(), ls2.end(), nums2[i]);
                if(it4 == ls2.end())
                    ls2.push_back(nums2[i]);
            }
        }

        ans.push_back(ls1);
        ans.push_back(ls2);

        return ans;
    }
};