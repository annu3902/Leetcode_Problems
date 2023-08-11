// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int n =arr.size();
//         int absnt_count = 0;

//         int maxi = 2000;
//         unordered_set<int> st(arr.begin(), arr.end());

//         for(int i =1; i <= maxi; i++)
//         {
//             if(st.find(i) == st.end()){
//                 absnt_count++;
//                 if(absnt_count == k){
//                     return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };

// class Solution{
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int num = 1;
//         int n = arr.size();
//         vector<int> missing(n);
//         int nums = 1;
//         for(int i =0; i<n; i++)
//         {
//             int diff = arr[i] - nums;
//             missing[i] = diff;
//             nums++;
//         }
//         int low = 0;
//         int high = n-1;
//         int ans = -1;

//         while(low <= high){
//             int mid = (low + high)/2;
//             if(arr[mid] >= k){
//                 ans = mid;
//                 high = mid - 1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
        
//         int cnt =0;
//         for(int i =0; i<n; i++)
//         {
//             if(missing[i] == 0){
//                 cnt++;
//             }
//         }
//         if(cnt == n){
//             return (n+k);
//         }

//         int extra = k - missing[high];
//         ans = extra + arr[high];
//         return ans;
//     } 
// };

class Solution{
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int n = arr.size();
        vector<int> missing(n);
        int nums = 1;
        for(int i = 0; i < n; i++) {
            int diff = arr[i] - nums;
            missing[i] = diff;
        }
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] - mid - 1 >= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        ans = low + k;
        return ans;
    } 
};
