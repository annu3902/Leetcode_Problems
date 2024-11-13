#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// *s.find_by_order , s.order_of_key 
// *s.find_by_order(x) -> It gives the Positon of the element we want i.e. x
// s.order_of_key(x) -> It gives the number of elements smaller tham this element i.e. x


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> pbds;
        int n = nums.size();
        long long ans = 0;
        pbds os;
        os.insert(nums[0]);
        for(int i=1;i<n;i++)
        {
            int right = upper - nums[i];
            int left = lower - nums[i];
            int right_range = os.order_of_key(right+1);
            int left_range = os.order_of_key(left);
            ans += (right_range - left_range);
            os.insert(nums[i]);
        }

           return ans;
        
    }
};