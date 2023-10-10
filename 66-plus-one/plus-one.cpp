// // class Solution {
// // public:
// //     vector<int> plusOne(vector<int>& digits) {
// //         int n = digits.size();
// //         for(int i= n-1; i>=0; i--){
// //             if(digits[i] != 9)
// //             {
// //                 digits[i]++;
// //                 return digits;
// //             }

// //             digits[i] =0;
// //         }
// //         digits.insert(digits.begin(),1);
// //         return digits;
// //     }
// // };

// // class Solution {
// //     public:
// //     vector<int> plusOne(vector<int> & digits){
// //         int n = digits.size();
// //         if(digits[n-1] != 9){
// //             digits[n-1]++;
// //         }
//    //      else if(digits[n-1] == 9){
// //             digits[n-1] =0;
// //             for(int i =n-2; i>=0; i--)
// //             {
// //                 if(digits[i] != 9)
// //                 {
// //                     digits[i]++;
// //                     break;
// //                 }
// //                 else{
// //                     digits[i] =0;
// //                 }
// //             }
// //             if(digits[0] == 0){
// //                 digits.insert(digits.begin(), 1);
// //             }
// //         }

// //         for(int i=0; i<n; i++){
// //             cout<<digits[i]<<" ";
// //         }
// //     return digits;
// //     }
// // };

// class Solution {
//     public:
//     vector<int> plusOne(vector<int> & digits){
//         int n = digits.size();
//         int i =n-1;
//         while(digits[i] == 9 && i>=0){
//             digits[i] =0;
//             i--;
//         }
//         if(i >= 0){
//             digits[i]++;
//         }
//         else if(digits[0] == 0){
//            digits.insert(digits.begin(),1);
//         }
//         for(int i=0; i<digits.size(); i++){
//         cout<<digits[i]<<" ";
//         }
//         cout<<endl;
//         return digits;
//    }
// };

// class Solution {
// public:
//     vector<int> plusOne(vector<int> & digits){
//         int n = digits.size();
//         int i = n-1;
//         while(digits[i] == 9 && i >= 0){
//             digits[i] = 0;
//             i--;
//         }
//         if(i >= 0){
//             digits[i]++;
//         }
//         else if(digits[0] == 0){
//             digits.insert(digits.begin(), 1);
//         }
//         for(int i=0; i<digits.size(); i++){
//             cout << digits[i] << " ";
//         }
//         cout << endl;
//         return digits;
//     }
// };

// class Solution {
// public:
//     vector<int> plusOne(vector<int>  digits){
//         int n = digits.size();
//         int i = n-1;

//         while(i >= 0 && digits[i] == 9 ){
//             digits[i] = 0;
//             i--;
//         }
//         if(i >= 0){
//             digits[i]=digits[i]+1;
//         }
//         else{
//             digits.insert(digits.begin(), 1);
//         }
//         // n = digits.size();
        
//         return digits;
//     }
// };

class Solution {
    public:
    vector<int> plusOne(vector<int> digits){
        int n =digits.size();

        for(int i=n-1; i>= 0; i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }

            else{
                digits[i] = 0;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};