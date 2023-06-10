class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // // vector<int> ans;
        // unordered_map<int,int> map;

        // for(int i=0; i<=nums.size()-1;i++)
        // {
        //     int difference = target-nums[i];
        //     if(map.find(difference)!=map.end())
        //     {
        //         // ans.push_back(i); 
        //         // ans.push_back(map[difference]);
        //         return {map[difference] , i};
        //     }
        //     map[nums[i]] =i;
        // }
        // // return ans;
        // return {-1,-1};

        vector <pair<int,int>> v;
        for(int i=0; i<nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(),v.end());

        int left =0;
        int right =v.size()-1;

        for(int i=0; i<v.size(); i++)
        {
            int sum = v[left].first + v[right].first;

            if(sum == target) {
                return {v[left].second, v[right].second};
            }

            else if(sum < target)
            {
                left++;
            }

            else{
                right--;
            }
        }
        return {-1,-1};
    }
};

        