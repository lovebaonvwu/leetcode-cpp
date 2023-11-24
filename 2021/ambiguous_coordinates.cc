class Solution {
 public:
  vector<string> ambiguousCoordinates(string s) {
    vector<string> ans;

    for (int i = 1; i < s.size() - 2; ++i) {
      vector<string> x, y;
      x = find(s.substr(1, i));
      y = find(s.substr(i + 1, s.size() - 1 - i - 1));

      for (auto& sx : x) {
        for (auto& sy : y) {
          ans.push_back("(" + sx + ", " + sy + ")");
        }
      }
    }

    return ans;
  }

  vector<string> find(string s) {
    int n = s.size();

    if (s == "") {
      return {};
    }

    if (s == "0") {
      return {s};
    }

    if (s[0] == '0' && s[s.size() - 1] == '0') {
      return {};
    }

    if (s[s.size() - 1] == '0') {
      return {s};
    }

    if (s[0] == '0') {
      return {"0." + s.substr(1)};
    }

    vector<string> ret{s};

    for (int i = 1; i < s.size(); ++i) {
      ret.push_back(s.substr(0, i) + "." + s.substr(i));
    }

    return ret;
  }
};
// Runtime: 8 ms, faster than 74.47%
// Memory Usage: 9.8 MB, less than 72.34%