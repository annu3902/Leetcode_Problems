class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi = 0;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i] > arr[maxi]){
                maxi = i;
            }
        }
        return maxi;
    }
};