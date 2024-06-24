class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        int currFlip = 0;
        unordered_map<int, bool> mp;

        for(int i=0; i < n; i++){

            if(i-k >= 0 && mp[i-k] == true){
                currFlip--;
            }

            if(((nums[i] == 0) && (currFlip & 1) == 0) || ((nums[i] == 1) && (currFlip & 1) == 1)){
                if(i+k <= n){
                    result++;
                    currFlip++;
                    mp[i] = true;
                }
                else{
                    return -1;
                }
            }

        }

        return result;

    }
};