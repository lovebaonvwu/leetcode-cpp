class Solution {
 public:
  int findMinimumOperations(string s1, string s2, string s3) {
    int len1 = s1.size();
    int len2 = s2.size();
    int len3 = s3.size();

    int i = 0;
    while (i < len1 && i < len2 && i < len3) {
      if (s1[i] == s2[i] && s1[i] == s3[i]) {
        ++i;
      } else
        break;
    }

    return i == 0 ? -1 : ((len1 - i) + (len2 - i) + (len3 - i));
  }
};
// 4ms
// 7.25MB