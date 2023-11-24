class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    vector<int> q_cnt;
    vector<int> w_cnt;

    count(queries, q_cnt);
    count(words, w_cnt);

    sort(w_cnt.begin(), w_cnt.end());

    vector<int> ans;

    for (int i = 0; i < q_cnt.size(); ++i) {
      int cnt =
          w_cnt.size() -
          (upper_bound(w_cnt.begin(), w_cnt.end(), q_cnt[i]) - w_cnt.begin());

      ans.push_back(cnt);
    }

    return ans;
  }

  void count(vector<string> ss, vector<int>& count) {
    for (const auto& s : ss) {
      int cnt = 0;
      char cur = 'z';
      for (const auto& ch : s) {
        if (ch < cur) {
          cur = ch;
          cnt = 1;
        } else if (ch == cur) {
          ++cnt;
        }
      }

      count.push_back(cnt);
    }
  }
};
// Runtime: 20 ms, faster than 86.67%
// Memory Usage: 11.7 MB, less than 100.00%

class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    vector<int> q_cnt;
    vector<int> w_cnt;

    count(queries, q_cnt);
    count(words, w_cnt);

    sort(w_cnt.begin(), w_cnt.end());

    vector<int> ans;

    for (int i = 0; i < q_cnt.size(); ++i) {
      int cnt =
          w_cnt.size() -
          (upper_bound(w_cnt.begin(), w_cnt.end(), q_cnt[i]) - w_cnt.begin());

      ans.push_back(cnt);
    }

    return ans;
  }

  void count(vector<string> ss, vector<int>& count) {
    for (const auto& s : ss) {
      vector<int> tmp(26, 0);

      for (const auto& ch : s) {
        tmp[ch - 'a']++;
      }

      for (const auto& n : tmp) {
        if (n > 0) {
          count.push_back(n);
          break;
        }
      }
    }
  }
};
// Runtime: 32 ms, faster than 49.34%
// Memory Usage: 15.2 MB, less than 100.00%

class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    vector<int> q_cnt;
    vector<int> w_cnt;

    count(queries, q_cnt);
    count(words, w_cnt);

    sort(w_cnt.begin(), w_cnt.end());

    vector<int> ans;

    for (int i = 0; i < q_cnt.size(); ++i) {
      auto it = upper_bound(w_cnt.begin(), w_cnt.end(), q_cnt[i]);

      int cnt = 0;

      for (; it != w_cnt.end(); ++it) {
        ++cnt;
      }

      ans.push_back(cnt);
    }

    return ans;
  }

  void count(vector<string> ss, vector<int>& count) {
    for (const auto& s : ss) {
      vector<int> tmp(26, 0);

      for (const auto& ch : s) {
        tmp[ch - 'a']++;
      }

      for (const auto& n : tmp) {
        if (n > 0) {
          count.push_back(n);
          break;
        }
      }
    }
  }
};
// Runtime: 32 ms, faster than 49.34%
// Memory Usage: 15.4 MB, less than 100.00%

class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    vector<int> q_cnt;
    vector<int> w_cnt;

    count(queries, q_cnt);
    count(words, w_cnt);

    vector<int> ans;

    for (int i = 0; i < q_cnt.size(); ++i) {
      int cnt = 0;
      for (int j = 0; j < w_cnt.size(); ++j) {
        if (q_cnt[i] < w_cnt[j]) {
          ++cnt;
        }
      }

      ans.push_back(cnt);
    }

    return ans;
  }

  void count(vector<string> ss, vector<int>& count) {
    for (const auto& s : ss) {
      vector<int> tmp(26, 0);

      for (const auto& ch : s) {
        tmp[ch - 'a']++;
      }

      for (const auto& n : tmp) {
        if (n > 0) {
          count.push_back(n);
          break;
        }
      }
    }
  }
};
// Runtime: 72 ms, faster than 15.19%
// Memory Usage: 15.2 MB, less than 100.00%