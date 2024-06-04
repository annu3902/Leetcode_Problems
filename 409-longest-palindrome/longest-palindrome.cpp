class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(), s.end());
        cout<<s;
        unordered_map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        int cnt = 0;
        bool flag = false;

        for(auto &[character, count] : mp){
            if(count & 1){
                // odd
                if(count > 1){
                    cnt += (count-1);
                    count = 1;
                }

                if(count == 1 && flag == false){
                    // cout<<"Hii ";
                    cnt += count;
                    flag = true;
                    // count = 0;
                }
            }

            else{
                // even
                cnt += count;
            }
        }
        return cnt;
    }
};