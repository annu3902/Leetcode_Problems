class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); // Number of lists
        
        // Map each number to the indices of the lists it appears in
        map<int, vector<int>> numToListIndices;
        for(int listIdx = 0; listIdx < k; listIdx++){
            for(int num : nums[listIdx]){
                numToListIndices[num].push_back(listIdx);
            }
        }
        
        // Flatten the map into arrays for easier processing with two pointers
        vector<int> sortedValues; // Sorted unique values
        vector<vector<int>> valueListIndices; // Corresponding list indices for each value
        for(auto& [value, indices] : numToListIndices){
            sortedValues.push_back(value);
            valueListIndices.push_back(indices);
        }
        
        // Variables to track the counts of list indices within the current window
        vector<int> windowCount(k, 0); // Count of occurrences for each list index in the sliding window
        int nonZeroCount = 0; // Number of lists currently covered in the window
        
        // Variables to track the smallest range found
        int minRange = INT_MAX;
        vector<int> ans = {0, 0};
        
        // Two pointers for the sliding window
        int i = 0, j = 0;
        
        // Start expanding the window by moving the right pointer
        while(j < valueListIndices.size()){
            // Include the current value's list indices in the window
            for(int listIdx : valueListIndices[j]){
                if(windowCount[listIdx] == 0) nonZeroCount++; // New list index covered
                windowCount[listIdx]++;
            }
            // Try to shrink the window from the left while all lists are covered
            while(nonZeroCount == k){
                // Update the smallest range if the current window is smaller
                int currentRange = sortedValues[j] - sortedValues[i];
                if(currentRange < minRange){
                    minRange = currentRange;
                    ans = {sortedValues[i], sortedValues[j]};
                }
                // Exclude the leftmost value's list indices from the window
                for(int listIdx : valueListIndices[i]){
                    windowCount[listIdx]--;
                    if(windowCount[listIdx] == 0) nonZeroCount--; // A list index is no longer covered
                }
                i++; // Move the left pointer to shrink the window
            }
            j++; // Move the right pointer to expand the window
        }
        return ans;
    }
};