class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> temp;
        temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        if(temp!=nums)
        {
            int largest = temp.size()-1;
            int smallest = 0;
            int x;
            for(int i=0; i<n; i++)
            {
                if(nums[i] == temp[largest] && i!=n-1)
                {
                    if(nums[i+1]==temp[smallest])
                    {
                        x=i+1;
                    }
                }
            }
            int cnt =0;
            for(int i=0; i<temp.size(); i++)
            {
                    // cout<<nums[i+x]%nums.size()<<" ";
                if(temp[i] == nums[(i+x)%n])
                {
                    cnt++;
                }
            }
            if(cnt == n)
            {
                return true;
            }else{
                return false;
            }
        }else{
            return true;
        }
    }
};

