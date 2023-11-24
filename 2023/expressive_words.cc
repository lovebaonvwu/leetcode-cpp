class Solution {
  vector<pair<char, int>> decode(const string& s) {
    vector<pair<char, int>> res;
    char prev = s[0];
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != prev) {
        res.push_back({prev, cnt});
        prev = s[i];
        cnt = 1;
      } else {
        ++cnt;
      }
    }

    res.push_back({prev, cnt});

    return res;
  }

 public:
  int expressiveWords(string s, vector<string>& words) {
    int ans = 0;
    auto s_code = decode(s);

    for (auto& w : words) {
      auto w_code = decode(w);

      if (s_code.size() != w_code.size()) {
        continue;
      }

      bool valid = true;
      for (int i = 0; i < s_code.size(); ++i) {
        auto& [s_char, s_cnt] = s_code[i];
        auto& [w_char, w_cnt] = w_code[i];

        if (s_char != w_char) {
          valid = false;
          break;
        }

        if (s_cnt < w_cnt) {
          valid = false;
          break;
        }

        if (s_cnt > w_cnt && s_cnt < 3) {
          valid = false;
          break;
        }
      }

      ans += valid;
    }

    return ans;
  }
};
// 8ms
// 9.57MB