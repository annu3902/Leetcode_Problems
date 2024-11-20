class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int maxi = 0;

        int a=0,b=0,c=0;
        for(auto x : s)
        {
            if(x=='a')a++;
            if(x=='b')b++;
            if(x=='c')c++;
        }
        
        if(a<k || b<k || c<k)return -1;
        if(k==0)return 0;

        a = a-k;
        b = b-k;
        c = c-k;

        int i=0;
        int j=0;
        int ac = 0,bc=0,cc=0;

        while(j<n)
        {
            if(s[j]=='a')ac++;
            else if(s[j]=='b')bc++;
            else cc++;

            if(ac > a || bc>b || cc>c)
            {
                while(i<=j)
                {
                    if(s[i]=='a')ac--;
                    else if(s[i]=='b')bc--;
                    else cc--;
                    i++;
                    if(ac <= a && bc<=b && cc<=c)
                    break;
                }
            }

           maxi = max(maxi,j-i+1); 
           j++;

        }
        return n-maxi;
    }
};

/*
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        
        int a=0,b=0,c=0;
        for(auto x : s)
        {
            if(x=='a')a++;
            if(x=='b')b++;
            if(x=='c')c++;
        }
        
        if(a<k || b<k || c<k)return -1;
        if(k==0)return 0;
        
        int mini = INT_MAX;
        vector<int> f(3,0);
        for(int i=-1;i<n;i++)
        {
            if(i>=0)
            f[s[i]-'a']++;
            
            vector<int> curr = f;
            int j = n;
            if(curr[0]<k || curr[1]<k || curr[2]<k)
            {
                j = n-1;
                while(j>i)
                {
                    curr[s[j]-'a']++;
                    if(curr[0]>=k && curr[1]>=k && curr[2]>=k)
                    break;
                    j--;
                }
            }
            int cnt = n-j;
            cnt += i+1;

            mini = min(mini,cnt);
        }

        return mini;
         
    }
};
*/