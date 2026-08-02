class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;
        // map<char,int> freq;
        Map<Character, Integer> freq = new HashMap<>();

        for(int right = 0; right < n; right++){
            // freq[s[right]]++;
            freq.put(s.charAt(right), freq.getOrDefault(s.charAt(right), 0) + 1);

            while(left <= right && freq.get(s.charAt(right)) > 1){
                // freq[s[left]]--;
                freq.put(s.charAt(left), freq.get(s.charAt(left)) - 1);
                left++;
            }

            int length = right - left + 1;
            maxLength = Math.max(maxLength, length);
     
        }

        return maxLength;
    }
}