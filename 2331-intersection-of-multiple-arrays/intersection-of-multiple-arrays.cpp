class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        // vector<set<int>> v;
        // set<int> st1;
        // set<int> st2;
        // set<int> st3;

        // for(vector<int> vec : nums){
        //     sort(vec.begin(), vec.end());  
        // }

        // for(vector<int> vec : nums){
        //     for(int i =0; i<nums.size(); i++){

        //     }
        // }

        // for(vector<int> vec : nums){
        //     set<int> st;
        //     for(int x : vec){
        //         st.insert(x);
        //     }
        //     v.push_back(st);
        // }

        // for(set<int> st : v){
        //     auto it;
        //     for(int x : st){
                
        //     }
        // }

        // for(int i = 0; i<nums.size(); i++){
        //     for(int j =0; j<nums[i].size(); j++){
        //         int element = nums[i][j];

        //     }
        // }
        vector<int> ans;
        vector<int> vec = nums[0];

        for(int x : vec){
            int cnt = 1;
            vector<int> :: iterator it;

            for(int i =1; i<nums.size(); i++){
                vector<int> v = nums[i];

                it = find(nums[i].begin(), nums[i].end(), x);
                if(it == nums[i].end()){
                    break;
                }else{
                    cnt++;
                }
            }

            if(cnt == nums.size()){
                ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};