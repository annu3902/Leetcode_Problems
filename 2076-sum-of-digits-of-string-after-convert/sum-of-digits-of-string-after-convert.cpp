class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();

        unordered_map<char, string> mp;
        int j = 97;
        for(int i=1; i<=26; i++){
            mp[j] = to_string(i);
            j++;
        }

        string nums ="";

        for(auto character : s){
            nums += mp[character];
        }

        int result = 0;
        for(int i = 0; i < k; i++){
            int ans = 0;
            for(auto str : nums){
                ans += str - '0';
            }
            result = ans;
            nums = to_string(ans);
        }

        return result;

    }
};