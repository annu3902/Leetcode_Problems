class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;

        for(int i=0; i<n; ++i){
            mpp[nums[i]]++;
        }

        multimap<int, int> mp;
        for(auto it : mpp){
            mp.insert(make_pair(it.second, it.first));
        }

        int cnt = 0;
        for(auto it:mp){
            if(it.first<k){
                k-=it.first;
                cnt++;
            }


            else if(it.first==k){
                k-=it.first;
                cnt++;

            }

            else{
                break;

            }
        }
        return mp.size()-cnt;
    }
};