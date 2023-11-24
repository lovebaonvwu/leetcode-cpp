class Solution {
 public:
  int maximumGain(string s, int x, int y) {
    if (y > x) {
      reverse(s.begin(), s.end());
      swap(x, y);
    }

    int ans = 0;

    string t;
    for (auto c : s) {
      t.push_back(c);

      if (t.size() >= 2 && t[t.size() - 2] == 'a' && t.back() == 'b') {
        t.pop_back();
        t.pop_back();
        ans += x;
      }
    }

    string u;
    for (auto c : t) {
      u.push_back(c);

      if (u.size() >= 2 && u[u.size() - 2] == 'b' && u.back() == 'a') {
        u.pop_back();
        u.pop_back();
        ans += y;
      }
    }

    return ans;
  }
};
// Runtime: 92 ms, faster than 82.69%
// Memory Usage: 24.5 MB, less than 51.05%
// 2022.4.1 at 奥盛大厦