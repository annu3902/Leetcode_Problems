class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int n =nums.size();
        int cnt = 0;

        for(int x : nums){
            if(x == mini) cnt++;
            else if(x % mini != 0) return 1;
        }

        return(cnt + 1)/2;
        
    }
};