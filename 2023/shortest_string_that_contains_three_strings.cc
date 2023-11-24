class Solution {
  string merge(string a, string b) {
    if (b.find(a) != string::npos) {
      return b;
    }

    int n = min(a.size(), b.size());
    int i = n;
    for (; i >= 0; --i) {
      if (a.substr(a.size() - i, i) == b.substr(0, i)) {
        break;
      }
    }

    return a.substr(0, a.size() - i) + b;
  }

  string combine(string a, string b, string c) {
    return update(merge(merge(a, b), c), merge(a, merge(b, c)));
  }

  string update(string ans, string res) {
    if (res.size() < ans.size()) {
      ans = res;
    } else if (res.size() == ans.size()) {
      ans = min(ans, res);
    }

    return ans;
  }

 public:
  string minimumString(string a, string b, string c) {
    string ans = a + b + c;
    ans = update(ans, combine(a, b, c));
    ans = update(ans, combine(a, c, b));
    ans = update(ans, combine(b, a, c));
    ans = update(ans, combine(b, c, a));
    ans = update(ans, combine(c, a, b));
    ans = update(ans, combine(c, b, a));

    return ans;
  }
};
// 480 ms
// 175.5 MB