class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i =0; int j =0;
        int maxi =0;
        unordered_map<char,int> mpp;
        while(j < n){
            mpp[s[j]]++;

            while(mpp[s[j]] > 1){
                int len = j-i;
                maxi = max(maxi,len);
                mpp[s[i]]--;
                i++;
            }
            cout<<maxi<<" ";
            j++;
        }
        maxi = max(maxi, j-i);
        cout<<endl;
        cout<<maxi;
        return maxi;
    }
};