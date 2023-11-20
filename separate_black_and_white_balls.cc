class Solution {
 public:
  long long minimumSteps(string s) {
    long long ans = 0;
    for (int i = 0, cnt = 0; i < s.size(); ++i) {
      if (s[i] == '1')
        ++cnt;
      else
        ans += cnt;
    }

    return ans;
  }
};
// 32ms
// 13.70MB