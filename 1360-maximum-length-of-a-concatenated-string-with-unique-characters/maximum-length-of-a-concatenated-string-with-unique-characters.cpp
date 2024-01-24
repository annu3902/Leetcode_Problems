class Solution {
public:
    // Simple Recursion
    int solve(vector<string> &arr, int i, string temp){
        // To decide which string is eligible to merge or not
        unordered_set<char> st(temp.begin(), temp.end());
        if(temp.size() != st.size()) return 0;
        // Base Case
        if(i >= arr.size()) return temp.size();

        // Pick
        int len1 = solve(arr, i + 1, temp + arr[i]);
        // Not Pick
        int len2 = solve(arr, i + 1, temp);

        int maxi = max(len1, len2);
        return maxi;
    }

    // TIME COMPLEXITY = 2^N * N * W; 
            // W -> Length of each word
            // N -> Size of the arr
    // Space Complexity = 2*(N * W)

    // Backtracking
    int solve2(vector<string> arr, int i, string &temp){
        unordered_set<char> st(temp.begin(), temp.end());
        if(temp.size() != st.size()) return 0;
        // Base Case
        if(i >= arr.size()) return temp.size();

        // Pick
        temp += arr[i];
        int len1 = solve(arr, i + 1, temp);
        
        // Not Pick
        for(char ch : arr[i]){
            temp.pop_back();
        }
        int len2 = solve(arr, i + 1, temp);

        return max({len1, len2});
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        return solve2(arr, 0, temp);
    }
};