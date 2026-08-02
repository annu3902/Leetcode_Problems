class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        int i=0;
        int j=n-1;
        
        while(i <= j){
            int x = j-i; // 9 
            int y = min(height[i], height[j]); //1

            int area = x*y;

            if(area > maxWater){
                maxWater = area;
            }
            if(height[i] >= height[j]){
                j--;
            }else{
                i++;
            }
        }

        return maxWater;
    }
};