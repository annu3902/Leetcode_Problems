class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(int x : nums){
            if(x > 0) pos.push_back(x);
            else neg.push_back(x);
        }

        int i=0;
        int j=0;
        vector<int> ans;
        while(i<pos.size() && j<neg.size()){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        return ans;
    }
};