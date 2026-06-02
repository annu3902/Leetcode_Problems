class Solution {
    public int longestSubstring(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];
        char[] str = s.toCharArray();
        
        for(char c : str){
            freq[c - 'a']++;
        }

        boolean valid = true;

        int start = 0;
        int maxLen = 0;
        for(int end = 0; end < n; end++){
            if(freq[str[end] - 'a'] < k){
                String substring = s.substring(start, end);
                maxLen = Math.max(maxLen, longestSubstring(substring, k));
                start = end+1;
                valid = false;
            }
        }

        if(valid == true){
            return n;
        }
        else{
            return maxLen = Math.max(maxLen, longestSubstring(s.substring(start), k));
        }
    }
}