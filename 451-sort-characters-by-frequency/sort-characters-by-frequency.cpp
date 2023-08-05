// class Solution {
// public:
//     string frequencySort(string s) {
//         string ans;
//         map<char,int> mpp;
//         for(int i=0; i<s.size(); i++)
//         {
//             mpp[s[i]]++;
//         }
//         multimap<int,char,greater<int>> mp;
//         for(auto it:mpp){
//             mp.insert({it.second,it.first});
//         }
//         for(auto x: mp){
//             int cnt = 0;
//             while(cnt < x.first){
//                 char ch = x.second;
//                 ans.push_back(ch);
//                 cnt ++;
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     string frequencySort(string s) {
//         string ans;
//         map<char, int> mpp;
//         for (char ch : s) {
//             mpp[ch]++;
//         }
//         multimap<int, char, greater<int>> mp;
//         for (auto entry : mpp) {
//             mp.insert({entry.second, entry.first});
//         }
//         for (auto entry : mp) {
//             int cnt = entry.first;
//             char ch = entry.second;
//             while (cnt > 0) {
//                 ans.push_back(ch);
//                 cnt--;
//             }
//         }
//         return ans;
//     }
// };

typedef pair<int,char> pi;
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(char c:s)
            m[c]++;
        priority_queue<pi> pq;
        for(auto it:m)
            pq.push({it.second,it.first});
        string s1="";
        while(!pq.empty())
        {
            int x=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            while(x--)
                s1.push_back(c);
        }
        return s1;
    }
};