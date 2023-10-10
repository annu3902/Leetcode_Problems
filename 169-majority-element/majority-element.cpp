// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n =nums.size();

//         //*********** MOORE'S VOTING ALGORITHM **********//

//         int element = nums[0];
//         int cnt =1;
//         int i =1;
        
//         while(i < n){
//             if(cnt > 0){
//                 if(nums[i] == element){
//                     cnt++;
//                 }else{
//                     cnt--;
//                 }
//             }

//             else{
//                 element = nums[i];
//                 cnt++;
//             }
//             i++;
//         }

//         if(cnt > 0)
//         {
//             int count =0;
//             for(int i=0; i<n; i++)
//             {
//                 if(nums[i] == element){
//                     count ++;
//                 }
//             }

//             if(count > n/2){
//                 return element;
//             }
//         }
//         return -1;
//     }
// };

class Solution{
    public :
    int majorityElement(vector<int>& nums){
        int n = nums.size();

        int cnt = 1;
        int ele = nums[0];

        for(int i = 1; i<n; i++){
            if(cnt > 0){
                if(nums[i] == ele)
                    cnt++;
                else{
                    cnt--;
                }
            }
            else{
                ele = nums[i];
                cnt++;
            }
        }

        if(cnt > 0){
            int count = 0;
            for(int i =0; i<nums.size(); i++){
                if(nums[i] == ele){
                    count ++;
                }
            }
            if(count > n/2){
                return ele;
            }
        }
        return -1;
    }

};