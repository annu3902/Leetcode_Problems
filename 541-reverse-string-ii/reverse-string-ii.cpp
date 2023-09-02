class Solution {
public:
    void reverseHelper(int left, int right, string &s){
        if(left >= right) return;
        
        swap(s[left], s[right]);
        reverseHelper(left+1, right-1, s);
    }

    string reverseStr(string s, int k) {
        int n = s.size();
        if(n < k){
            reverse(s.begin(), s.end());
            return s;
        }

       int x = 2*k;
       int total_grps = ceil(n/x);
       int left = 0;
       int right = k-1;

        for(int i =0; i<=total_grps; i++){
            reverseHelper(left, right, s);
            left = left + 2*k;
            right = min(left + k -1, n-1);
        }

        return s;
    }
};

// class Solution {
// public:
//     void reverseHelper(int left, int right, string &s) {
//         if (left >= right) return;

//         swap(s[left], s[right]);
//         reverseHelper(left + 1, right - 1, s);
//     }

//     string reverseStr(string s, int k) {
//         int n = s.size();
//         if (n < k) {
//             reverse(s.begin(), s.end());
//             return s;
//         }

//         int x = 2 * k;
//         int total_grps = n / x;
        
//         for (int i = 0; i <= total_grps; i++) {
//             int left = i * x;
//             int right = min(left + k - 1, n - 1);
//             reverseHelper(left, right, s);
//         }

//         return s;
//     }
// };
