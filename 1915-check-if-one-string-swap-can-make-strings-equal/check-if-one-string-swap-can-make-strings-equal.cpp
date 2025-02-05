class Solution {
public:
    // Time complexity: O(N), Space complexity: O(1)
    bool areAlmostEqual(string s1, string s2) {
      int N = s1.size(), idx1 = -1, idx2 = -1;

      // when both s1 and s2 are same, no need for any swap operation
      if (s1 == s2) {
        return true;
      }

      for(int i = 0; i < N; ++i) {
        if (s1[i] != s2[i]) {
          if (idx1 == -1) {
            idx1 = i;
          } else if (idx2 == -1) {
            idx2 = i;
          } else if (idx1 != -1 && idx2 != -1) { // when more than 2 elements are different in both s1 and s2
            return false;
          }
        }
      }

      // exactly one swap operation
      if (idx1 != -1 && idx2 != -1 && s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1]) {
        return true;
      }

      return false;
    }
};