class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        int count=0;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                int p=-1;
                for(int k=j-1;k>i;k--)
                {
                    if(s[k]==s[i])
                    {
                        p=k;
                        break;
                    }
                }
                if(p!=-1)
                {
                    for(int k=p;k<j;k++)
                    {
                        swap(s[k],s[k+1]);
                        count++;
                    }
                }
                else{
                    swap(s[i],s[i+1]);
                    count++;
                }
            }
        }
        return count;
    }
};