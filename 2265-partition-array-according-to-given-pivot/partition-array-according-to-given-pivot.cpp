class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> temp1;
        vector<int> temp2;
        vector<int> temp3;

        for(int x : nums){
            if(x < pivot) temp1.push_back(x);
            else if(x > pivot) temp2.push_back(x);
            else temp3.push_back(x);
        }
        for(int x : temp3){
            cout<<x<<" ";
        }

        vector<int> ans;
        int i=0;
        while(i<temp1.size()){
            ans.push_back(temp1[i++]);
        }
        int j=0;
        while(j<temp3.size()){
            ans.push_back(temp3[j++]);
        }
        int k=0;
        while(k<temp2.size()){
            ans.push_back(temp2[k++]);
        }
        return ans;
    }
};