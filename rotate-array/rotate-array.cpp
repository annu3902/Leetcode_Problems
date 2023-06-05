class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k = k%n;
        int d=n-k;
        vector<int> vec;
        for(int i=0; i<d; i++)
        {
            vec.push_back(nums[i]);
        }
        for(int i=d; i<n; i++)
        {
            nums[i-d]=nums[i];
        }
        int j=0;
        for(int i=k; i<n; i++)
        {
            nums[i]=vec[j];
            j++;
        }
    }
};