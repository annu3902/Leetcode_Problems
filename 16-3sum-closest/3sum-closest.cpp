class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++){
            int left = i + 1; int right = n - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return target;
                else if(sum < target){
                    int temp = abs(sum - target);
                    arr.push_back({sum, temp});
                    left++;
                }   
                else{
                    int temp = abs(sum - target);
                    arr.push_back({sum, temp});
                    right--;
                }
            }
        }

        int comp = INT_MAX;
        int res;
        // for(pair<int, int> p : arr){
        //     int firstEle = p.first;
        //     int secondEle = p.second;
        //     if(secondEle < comp){
        //         comp = secondEle;
        //         res = firstEle;
        //     }
        // }
        
        int m = arr.size();
        for(int i = 0; i < m; i++){
            pair<int, int> element = arr[i];
            if(element.second < comp){
                comp = element.second;
                res = element.first;
            }
        }
        return res;
    }
};