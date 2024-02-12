class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        cout<<n<<endl;
        sort(nums.begin(), nums.end());
        int cnt = 1;
        vector<int> ans;
        int element = nums[0];

        for(int i=1; i<n; ++i){
            if(nums[i] == nums[i-1]){
                element = nums[i];
                cnt++;
            }
            else{
                cout<<element<<" "<<cnt<<endl;
                if(cnt > ceil(n/3)){
                    ans.push_back(element);
                }
                    element = nums[i];
                    cnt = 1;
            }  
        }
        if(cnt > n/3){
        cout<<element<<" "<<cnt<<endl;
            ans.push_back(element);
        }
        return ans;
        
    }
};