class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        map<int, long long> mp; // map will store the key as the (nums[i] - i) and value as the sum 
        long long maxSum = INT_MIN;

        for(int i=0; i<n; i++){
            long long sum = nums[i];

            auto it = mp.upper_bound(nums[i]-i); // it will return the iterator to the element which is just greater than the nums[i] present in the map

            if(it != mp.begin()){
                it--;
                sum += it->second;
            } // if iterator is pointing to the beginning then we will not decrement the iterator
            mp[nums[i]-i] = max(mp[nums[i]-i], sum);
            // mp[nums[i]-i] = sum;

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && it->second <= sum){
                mp.erase(it++);
            }
            // cout<<maxSum<<" "<<sum<<" "<<mp[nums[i]-i]<<endl;
            maxSum = max(maxSum, sum);           

        }

        return maxSum;

    }
};

/*class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};*/