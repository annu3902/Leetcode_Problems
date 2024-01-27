class Solution {
public:

    // Method 1 -> Recursion (Gives TLE)
    // bool check(string s, string t, string temp, int ind){
    //     int n = s.size();
    //     int m = t.size();

    //     // Base Case
    //     if(temp.size() == n){
    //         if(temp == s) return true;
    //         return false;
    //     }

    //     if(ind >= m) return false;
    //     // Pick
    //     temp.push_back(t[ind]);
    //     bool res1 = check(s, t, temp, ind +1);
    //     // Not Pick
    //     temp.pop_back();
    //     bool res2 = check(s, t, temp, ind + 1);
    //     return res1 | res2;
    // }

    // bool isSubsequence(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();

    //     if(n > m) return false;

    //     else if(n == m){
    //         if(s == t) return true;
    //         else return false;
    //     }

    //     return check(s, t, "", 0);
    // }

    bool isSubsequence(string s, string t){
        int n = s.size();
        int m = t.size();

        if(n > m) return false;

        else if(n == m){
            if(s == t) return true;
            return false;
        }

        queue<char> q;
        for(int i = 0; i < n; i++){
            q.push(s[i]);
        }

        int i = 0;
        while(!q.empty()){
            int element = q.front();
            while(i < m && t[i] != element){
                i++;
            }
            if(i == m){
                return false;
            }
            q.pop();
            i++;
        }
        return true;
    }
};