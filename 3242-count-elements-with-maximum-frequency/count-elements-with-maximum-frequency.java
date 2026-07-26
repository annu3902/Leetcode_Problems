class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int maxFreq = 0;
        int ans = 0;

        for(int i=0; i<nums.length; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
            if(maxFreq < mp.get(nums[i])){
                maxFreq = mp.get(nums[i]);
            }
        }

        for(int num : mp.keySet()){
            if(mp.get(num) == maxFreq) ans += maxFreq;
        }

        return ans;
    }
}