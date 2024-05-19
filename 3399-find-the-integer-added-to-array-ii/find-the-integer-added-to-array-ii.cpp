class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int mini = INT_MAX;

        for(int i=0; i<nums1.size(); i++){

            for(int j=i+1; j<nums1.size(); j++){
                vector<int> updatedNums1;
                for(int k=0; k<nums1.size(); k++){
                    if(k != i && k != j)
                        updatedNums1.push_back(nums1[k]);
                }

                int diff;
                bool flag = false;
                for(int k = 0; k < updatedNums1.size(); k++){
                    if(k == 0){
                        diff = nums2[0] - updatedNums1[0];
                    }
                    else if(nums2[k] - updatedNums1[k] != diff){
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                else{
                    mini = min(mini, diff);
                }
            }

        }
        return mini;
    }
};