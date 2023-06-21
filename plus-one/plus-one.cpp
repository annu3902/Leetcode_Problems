// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int n = digits.size();
//         for(int i= n-1; i>=0; i--){
//             if(digits[i] != 9)
//             {
//                 digits[i]++;
//                 return digits;
//             }

//             digits[i] =0;
//         }
//         digits.insert(digits.begin(),1);
//         return digits;
//     }
// };

class Solution {
    public:
    vector<int> plusOne(vector<int> & digits){
        int n = digits.size();
        if(digits[n-1] != 9){
            digits[n-1]++;
        }
        else if(digits[n-1] == 9){
            digits[n-1] =0;
            for(int i =n-2; i>=0; i--)
            {
                if(digits[i] != 9)
                {
                    digits[i]++;
                    break;
                }
                else{
                    digits[i] =0;
                }
            }
            if(digits[0] == 0){
                digits.insert(digits.begin(), 1);
            }
        }

        for(int i=0; i<n; i++){
            cout<<digits[i]<<" ";
        }
    return digits;
    }
};