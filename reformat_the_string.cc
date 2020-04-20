class Solution {
 public:
  string reformat(string s) {
    vector<char> d;
    vector<char> c;

    for (auto ch : s) {
      if (isdigit(ch)) {
        d.push_back(ch);
      } else {
        c.push_back(ch);
      }
    }

    if (abs(static_cast<int>(d.size() - c.size())) > 1) {
      return "";
    }

    string ans;
    if (d.size() > c.size()) {
      ans += d.back();
      d.pop_back();
    } else if (c.size() > d.size()) {
      ans += c.back();
      c.pop_back();
    }

    while (!d.empty() || !c.empty()) {
      if (ans.empty() || isdigit(ans.back())) {
        ans += c.back();
        c.pop_back();
      } else {
        ans += d.back();
        d.pop_back();
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 72.73%
// Memory Usage: 7.7 MB, less than 100.00%

class Solution {
 public:
  string reformat(string s) {
    int ch_cnt = 0;
    int num_cnt = 0;

    for (auto ch : s) {
      isdigit(ch) ? ++num_cnt : ++ch_cnt;
    }

    if (abs(num_cnt - ch_cnt) > 1) {
      return "";
    }

    int num_idx = 0;
    int ch_idx = 0;

    string ans;

    while (ans.size() < s.size()) {
      if ((ans.size() & 1) ^ (num_cnt > ch_cnt)) {
        while (isalpha(s[num_idx])) {
          ++num_idx;
        }
        ans += s[num_idx++];
      } else {
        while (isdigit(s[ch_idx])) {
          ++ch_idx;
        }
        ans += s[ch_idx++];
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 72.73%
// Memory Usage: 7.2 MB, less than 100.00%