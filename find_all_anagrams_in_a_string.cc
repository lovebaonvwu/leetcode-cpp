class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return vector<int>{};
    }

    vector<int> pv(26);
    vector<int> sv(26);

    for (int i = 0; i < p.size(); ++i) {
      ++pv[p[i] - 'a'];
      ++sv[s[i] - 'a'];
    }

    vector<int> ans;

    if (pv == sv) {
      ans.push_back(0);
    }

    int n = p.size();
    for (int i = p.size(); i < s.size(); ++i) {
      ++sv[s[i] - 'a'];
      --sv[s[i - n] - 'a'];

      if (pv == sv) {
        ans.push_back(i - n + 1);
      }
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 55.24%
// Memory Usage: 10.3 MB, less than 96.15%

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return {};
    }

    vector<int> hole(26);

    for (auto& c : p) {
      ++hole[c - 'a'];
    }

    vector<int> ans;

    vector<int> tmp_hole;

    for (int i = 0; i <= s.size() - p.size(); ++i) {
      tmp_hole = hole;

      for (int j = 0; j < p.size(); ++j) {
        if (--tmp_hole[s[i + j] - 'a'] < 0) {
          break;
        }
      }

      if (all_of(tmp_hole.begin(), tmp_hole.end(),
                 [](int n) { return n == 0; })) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 872 ms, faster than 5.45%
// Memory Usage: 10.3 MB, less than 90.38%

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return {};
    }

    vector<int> hole(26);

    for (auto& c : p) {
      ++hole[c - 'a'];
    }

    vector<int> ans;

    vector<int> tmp_hole;

    for (int i = 0; i <= s.size() - p.size(); ++i) {
      tmp_hole = hole;

      for (int j = 0; j < p.size(); ++j) {
        tmp_hole[s[i + j] - 'a']--;
      }

      if (all_of(tmp_hole.begin(), tmp_hole.end(),
                 [](int n) { return n == 0; })) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 1220 ms, faster than 5.04%
// Memory Usage: 10.4 MB, less than 75.00%