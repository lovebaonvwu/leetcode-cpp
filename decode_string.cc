class Solution {
 public:
  string decodeString(string s) { return decodeSub(s, 0, s.size() - 1); }

  string decodeSub(string& s, int begin, int end) {
    string ans;
    int cur = begin;

    while (cur <= end) {
      if (isalpha(s[cur])) {
        ans += s[cur++];
      } else {
        int multiplier = atoi(&s[cur++]);

        while (s[cur] != '[') {
          ++cur;
        }

        int cnt = 1;
        begin = ++cur;

        while (cnt) {
          if (s[cur] == '[') {
            ++cnt;
          } else if (s[cur] == ']') {
            --cnt;
          }

          ++cur;
        }

        string sub = decodeSub(s, begin, cur - 2);

        while (multiplier--) {
          ans += sub;
        }
      }
    }

    return ans;
  }
};