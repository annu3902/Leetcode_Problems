class Solution {
    public boolean canEat(int[] piles, int h, int k){
        int n = piles.length;
        int totalHrs = 0;

        for(int i=n-1; i>=0; i--){
            double timeRequire = Math.ceil((double)piles[i]/k);
            totalHrs += timeRequire;
            if(totalHrs > h) return false;
        }

        return true;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        Arrays.sort(piles);

        if(h < n) return -1;

        int left = 1;
        int right = piles[n-1];

        while(left < right){
            int mid = left + (right - left)/2;
            if(canEat(piles, h, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return right;
    }
}