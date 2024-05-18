class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m) return false;

        map<char, int> mpp1;
        map<char, int> mpp2;

        for(int i = 0; i < n; i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }

        auto it1 = mpp1.begin();
        auto it2 = mpp2.begin();

        for(; it1 != mpp1.end(); it1++){

            pair<char, int> p1 = *it1;
            pair<char, int> p2 = *it2;
            char ch1 = p1.first;
            int cnt1 = p1.second;
            char ch2 = p2.first;
            int cnt2 = p2.second;

            cout<<ch1<<" "<<ch2<<endl;

            if(ch1 != ch2 ) return false;
            else if(cnt1 != cnt2) return false;
            // else if(ch1 != ch2) return false;
            it2++;
        }
        return true;

    }
};