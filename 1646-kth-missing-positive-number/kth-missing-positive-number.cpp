class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n =arr.size();
        int absnt_count = 0;

        int maxi = 2000;
        unordered_set<int> st(arr.begin(), arr.end());

        for(int i =1; i <= maxi; i++)
        {
            if(st.find(i) == st.end()){
                absnt_count++;
                if(absnt_count == k){
                    return i;
                }
            }
        }
        return -1;
    }
};