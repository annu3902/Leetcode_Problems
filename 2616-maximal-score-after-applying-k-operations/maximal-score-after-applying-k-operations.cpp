class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> p(nums.begin(),nums.end());
        long long score=0;
        while(k--){
            int temp=p.top();
            p.pop();
            score+=temp;
            if(temp%3==0)
            p.push(temp/3);
            else
            p.push(temp/3+1);

        }
        return score;
        
    }
};