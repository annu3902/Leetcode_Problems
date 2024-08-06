// class Solution {
// public:
//     int minimumPushes(string word) {
//         int count = 0;
//         int n = word.size();  
//         map<char, int> mpp;
        
//         for(char ch : word){
//             mpp[ch]++;
//         }
        
// //         auto it = mpp.end();
// //         int m = mpp.size();
        
// //         for(; it != mpp.begin(); it--){
// //             int times = (it)->second;
// //             char element = (it)->first;
            
// //             if(m <= 8){
// //                 count += times;
// //             }else if(m > 8 && m <= 16){
// //                 count =count +2*(times);
// //             }
// //             else{
// //                 count = count + 3 * (times);
// //             }
// //         }
// //         return count;
        
//         priority_queue<pair<int, char> , vector<pair<int, char>>, greater<pair<int , char>>> pq;
//         for(char ch : word){
//             pq.push({mpp[ch] , ch});
//         }
        
//         int i =1;
//         for(pair<int, char> p : pq){
//             int times = p.first;
//             char element = p.second;
            
//             if(i <= 8){
//                 count += times;
//             }
            
//             else if (i <= 16){
//                 count = count + 2*(times);
//             }
            
//             else if(i <= 24){
//                 count = count + 3*(times);
//             }
            
//             else{
//                 count += count + 4*(times);
//             }
//             i++;
//         }
//         return count;
        
        
// //         for(pair<char, int> p : mpp){
// //             char element = p.first;
// //             int times = p.second;
            
// //             if(m <= 8){
// //                 count += times;
// //             }else{
                
// //             }
// //         }
//     }
// };

class Solution {
public:
    int minimumPushes(string word) {
        int count = 0;
        map<char, int> mpp;
        
        for(char ch : word){
            mpp[ch]++;
        }
        
        priority_queue<int> pq;
        for(auto entry : mpp){
            pq.push(entry.second);
        }
        
        int i = 1;
        while(!pq.empty()){
            int times = pq.top();
            pq.pop();
            
            if(i <= 8){
                count += times;
            }
            
            else if (i <= 16){
                count += 2*(times);
            }
            
            else if(i <= 24){
                count += 3*(times);
            }
            
            else{
                count += 4*(times);
            }
            i++;
        }
        
        return count;
    }
};
