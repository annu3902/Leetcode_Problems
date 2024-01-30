class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int cnt = 0;    

        // Creating a subarray of size k / Sliding Window
        for(int i = 0; i < k; i++){
            if(st.count(s[i])) cnt++;
        }

        int endIndex = k;
        int startIndex = 0;
        int maxLength = cnt;

        while(endIndex < n){
            if(st.count(s[startIndex])) cnt--;
            startIndex++;

            if(st.count(s[endIndex])) cnt++;
            endIndex++;

            maxLength = max(maxLength, cnt);
        }
        return maxLength;
    }
};