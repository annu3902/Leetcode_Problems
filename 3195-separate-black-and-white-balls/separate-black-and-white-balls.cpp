// class Solution {
// public:
//     long long minimumSteps(string s) {
//         int cntOnes = 0;
//         long long int ans = 0;
//         for(int i =0; i<s.size(); i++){
//             if(s[i] == '1') cntOnes++;
//             else{
//                 ans = ans + cntOnes;
//             }
//         }
//         return ans;
//     }
// };

class Solution{
    public:
        long long minimumSteps(string s){
            vector<int> zeroes;
            vector<int> ones;
            
            for(int i =0; i<s.size(); i++){
                if(s[i] == '0'){
                    zeroes.push_back(i);
                }
                else{
                    ones.push_back(i);
                }
            }
            
            for(int i=0; i<zeroes.size(); i++){
                cout<<zeroes[i]<<" ";
            }

            cout<<endl;

            for(int i=0; i<ones.size(); i++){
                cout<<ones[i]<<" ";
            }

            int i = 0;
            int j = zeroes.size() - 1;
            long long int ans = 0;
            
            while(j >= 0 && i < ones.size()){
                if(ones[i] > zeroes[j]){
                    break;
                }
                // else{
                    ans = ans + abs(zeroes[j] - ones[i]);
                // }
                i++;
                j--;
            }
            return ans;
        }      
};