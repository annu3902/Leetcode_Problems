class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, n = s.size();
        int ans = 0;
        vector<int> cnt(26,0);

        for(; right < n; right++){
            cnt[s[right] - 'A']++;
            // int maxi = *max_element(cnt.begin(), cnt.end());

            while((right - left + 1) - *max_element(cnt.begin(), cnt.end()) > k){
                cnt[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, (right - left + 1));
        }
        return ans;
    }
};