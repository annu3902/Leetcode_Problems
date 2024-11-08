class Solution
{
public:
    std::vector<int> getMaximumXor(std::vector<int> &nums, int maximumBit)
    {
        std::vector<int> result(nums.size(),0);
        int mask = 0;
        for(int i = 0 ; i <maximumBit ; i++)
        {
            mask<<=1;
            mask++;
        }

        if(result.size() < 2)
        {
            result[0] = (nums[0]^mask);
            return result;
        }
        size_t n = result.size()-2;
        std::vector<int> dpArr(nums.size());
        dpArr[0] = nums[0];
        result[n+1] = (nums[0]^mask);
        for(size_t i = 1 ; i <nums.size() ; i++)
        {
            dpArr[i] = dpArr[i-1]^nums[i];
            result[n--] = (dpArr[i]^mask);
        }

        return result;
    }
};