class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        map<char, int> mpp1;
        map<char, int> mpp2;

        if(n != m) return false;

        for(int i = 0; i < n; i++){
            char sh = s[i];
            char th  = t[i];
            mpp1[sh]++;
            mpp2[th]++;
        }

        // auto it1 = mpp1.begin();
        // auto it2 = mpp2.begin();

        // for(; it1 != mpp1.end(); it1++){

        //     pair<char, int> p1 = *it1;
        //     pair<char, int> p2 = *it2;
        //     char ch1 = p1.first;
        //     int cnt1 = p1.second;
        //     char ch2 = p2.first;
        //     int cnt2 = p2.second;

        //     if(ch1 != ch2 ) return false;
        //     else if(cnt1 != cnt2) return false;
        //     // else if(ch1 != ch2) return false;
        // }
        auto it = mpp2.begin();
        for(pair<char, int> p : mpp1){
            char ch = p.first;
            int cnt = p.second;

            pair<char, int> p2 = *it;
            char ch2 = p2.first;
            int cnt2 = p2.second;

            if(ch != ch2) return false;
            else if (ch == ch2 && cnt != cnt2) return false;
            it++;
        }
        return true;
    }
};