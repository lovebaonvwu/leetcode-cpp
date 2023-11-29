class Solution {
  bool is_vowels(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  int beautifulSubstrings(string s, int k) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int v_cnt = 0;
      int c_cnt = 0;
      for (int j = i; j < n; ++j) {
        if (is_vowels(s[j])) {
          ++v_cnt;
        } else {
          ++c_cnt;
        }

        if (v_cnt == c_cnt && (v_cnt * c_cnt % k == 0)) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// 30ms
// 6.87MB