// // class Solution {
// // public:

// // int solve(vector<string> &arr, int i, string &temp, int length, int maxi, set<char> st){
// //     // Base Case
// //     if(i == arr.size()){
// //         maxi = max(maxi, length);
// //         return maxi;
// //     }

// //     // Pick
// //     bool flag = 0;
// //     for(char c : arr[i]){
// //         if(st.count(c)) flag = 1;
// //     }

// //     if(flag == 0){
// //         temp += arr[i];
// //         for(char c : st){
// //             st.insert(c);
// //         }
// //         return solve(arr, i + 1, temp, length + arr[i].size(), maxi, st);
// //     // Not Pick
// //         for(char c : st){
// //             st.erase(c);
// //         }
// //         temp.pop_back();
// //         return solve(arr, i + 1, temp, length, maxi, st);
// //     }
    
// //     else{
// //         return solve(arr, i + 1, temp, length, maxi, st);
// //     }

// // }

// //     int maxLength(vector<string>& arr) {
// //         string temp ="";
// //         set<char> st;
// //         return solve(arr, 0, temp, 0, 0, st);
// //     }
// // };


class Solution{
    public:

    int solve(vector<string> &arr, int pos, string temp, vector<bool> hashArr){
        //  Base Case
        if(pos >= arr.size()) return 0;
        // Processing
        int len1 = INT_MIN;
        // Pick
        bool flag = 0;
        int i = 0;
        for(i=0;i<arr[pos].size();i++){
            if(hashArr[arr[pos][i]-'a']==0) hashArr[arr[pos][i]-'a'] =  1;
            else break;
        }
        if(i==arr[pos].size()){
            len1 = arr[pos].size() + solve(arr, pos + 1, temp , hashArr);
        }
        // Not Pick
        for(int j=0;j<i;j++){
           hashArr[arr[pos][j]-'a'] = 0;
        }
        
        int len2 = solve(arr, pos + 1, temp, hashArr);
        

        int maxi = max(len1,len2);
        return maxi;
    }

    int maxLength(vector<string> &arr){
        vector<bool> hashArr(27 , 0);
        string temp = "";
        return solve(arr, 0, temp, hashArr);
    }
};

// class Solution {
// public:
//     int solve(vector<string> &arr, int pos, string temp, vector<bool> hashArr) {
//         if (pos >= arr.size()) {
//             return temp.size();
//         }

//         bool flag = false;
//         for (char ch : arr[pos]) {
//             if (hashArr[ch - 'a']) {
//                 flag = true;
//                 break;
//             }
//             hashArr[ch - 'a'] = true;
//         }

//         int len1 = 0, len2 = 0, len3 = 0;

//         if (!flag) {
//             string temp1 = temp + arr[pos];
//             len1 = solve(arr, pos + 1, temp1, hashArr);
//         }

//         for (char ch : arr[pos]) {
//             hashArr[ch - 'a'] = false;
//         }

//         len2 = solve(arr, pos + 1, temp, hashArr);
        
//         int maxi = max({len1, len2, len3});
        
//         return maxi;
//     }

//     int maxLength(vector<string> &arr) {
//         vector<bool> hashArr(26 , false);
//         string temp = "";
        
//         return solve(arr, 0, temp, hashArr);
//     }
// };
