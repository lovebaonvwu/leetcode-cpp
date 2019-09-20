class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    int b = 0;
    int a = 0;
    int l = 0;
    int o = 0;
    int n = 0;

    for (const auto& ch : text) {
      if (ch == 'b')
        ++b;
      if (ch == 'a')
        ++a;
      if (ch == 'l')
        ++l;
      if (ch == 'o')
        ++o;
      if (ch == 'n')
        ++n;
    }

    int ans = b;

    if (a < ans)
      ans = a;
    if (l / 2 < ans)
      ans = l / 2;
    if (o / 2 < ans)
      ans = o / 2;
    if (n < ans)
      ans = n;

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.8 MB, less than 100.00%

class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    int ans{0};

    int items[26]{0};

    for (const auto& ch : text) {
      items[ch - 'a'] += 1;
    }

    const string tpl = "balloon";

    while (1) {
      bool fin = false;
      for (const auto& ch : tpl) {
        if (!items[ch - 'a']) {
          fin = true;
          break;
        }

        items[ch - 'a']--;
      }

      if (fin) {
        break;
      }

      ++ans;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 89.06%
// Memory Usage: 8.9 MB, less than 100.00%