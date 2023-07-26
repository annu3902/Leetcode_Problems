class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // int n = arr.size();
        // vector<int> hashh;

        // sort(arr.begin(), arr.end());
        // int i =0;
        // int cnt =1;
        // for(int j=i+1; j<n; j++)
        // {
        //     if(arr[j] == arr[i]){
        //         cnt++;
        //     }
        //     else{
        //         hashh.push_back(cnt);
        //         i = j;
        //         j = i+1;
        //         cnt = 1;
        //     }
        // }
        // sort(hashh.begin(), hashh.end());
        // // int j =0;
        // for(int i=1; i<hashh.size(); i++)
        // {
        //     if(hashh[i] == hashh[i-1]){
        //         // j++;
        //         return false;
        //     }
        // }
        // return true;

        int n =arr.size();
        map<int,int> mpp;
        for(int i=0; i<n; i++)
        {
            mpp[arr[i]]++;
        }
        vector<int>v;
        for(auto it: mpp)
        {
            int value = it.second;
            v.push_back(value);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i];
        }

        for(int i=1; i<v.size(); i++)
        {
            if(v[i] == v[i-1]){
                return false;
            }
        }
        return true;
    }
};