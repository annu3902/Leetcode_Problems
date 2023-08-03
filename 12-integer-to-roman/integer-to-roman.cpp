// class Solution {
// public:
//     string intToRoman(int num) {
//         unordered_map<int,char> mpp{
//             {1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'},{4,'IV'},{9,'IX'} ,             {40,'XL'},{90,'XC'},{400,'CD'},{900,'CM'};
//         };
//         string s;
//         vector<int> v;
//         while(num != 0){
//             int ld = num % 10;
//             v.push_back(ld);
//         }
//         int n =v.size();
//         // int sum =0;
//         for(int i =0; i<n; i++)
//         {
//             v[i]= (v[i]*pow(10,i));
//         }
//         for(int i =n-1; i>=0; i--)
//         {
//             if(mpp.find(s[i]) != mpp.end()){
//                 s.push_back(mpp[s[i]]);
//                 num -= s[i];
//             }

//             else{
//                 s[i]

                
//             }
//         }
        
//     }
// };

class Solution {
public:
    string intToRoman(int num) {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        for(int i=0; num != 0; i++){
            while(num >= val[i]){
                num -= val[i];
                res += sym[i];
            }
        }
        return res;
    }
};