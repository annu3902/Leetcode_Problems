class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = arr.size();
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        if(target == arr) return true;

        return false;
    }
};

// 9 8 7 4 6
// 9 8 4 7 6
// 9 4 8 7 6