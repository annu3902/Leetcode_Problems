class Solution {
public:

void helper(vector<int>& arr, int pos, vector<int>& subset, vector<vector<int>> &ans){
    if(pos == arr.size()){
        ans.push_back(subset);
        return;
    }

    // Doing my small task first to include or exclude the element

        // Include the element
        subset.push_back(arr[pos]);
        helper(arr, pos+1, subset, ans);

        // Exclude the element
        subset.pop_back();
        // Surpass the element till the new element is equal to the previous one
        while(pos+1 < arr.size() && arr[pos] == arr[pos+1]){
            pos++;
        }
        helper(arr, pos+1, subset, ans);
}
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    vector<int> subset;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    helper(arr, 0, subset, ans);
    sort(ans.begin(), ans.end());
    return ans;
    }
};

