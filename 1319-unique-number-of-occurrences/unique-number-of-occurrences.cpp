class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v;
        int n =arr.size();

        sort(arr.begin(), arr.end());
        int cnt =1;

        for(int i=1; i<n; i++)
        {
            if(arr[i] == arr[i-1]){
                cnt++;
            }else{
                v.push_back(cnt);
                // i = j;
                cnt =1;
            }
        }
        v.push_back(cnt);
        sort(v.begin(), v.end());

        for(int i=1; i<v.size(); i++)
        {
            if(v[i] == v[i-1]){
                return false;
            }
        }
        return true;



        // int n =arr.size();
        // map<int,int> mpp;
        // for(int i=0; i<n; i++)
        // {
        //     mpp[arr[i]]++;
        // }
        // vector<int>v;
        // for(auto it: mpp)
        // {
        //     int value = it.second;
        //     v.push_back(value);
        // }
        // sort(v.begin(), v.end());
        // for(int i=0; i<v.size(); i++)
        // {
        //     cout<<v[i];
        // }

        // for(int i=1; i<v.size(); i++)
        // {
        //     if(v[i] == v[i-1]){
        //         return false;
        //     }
        // }
        // return true;
    }
};