class Solution {
  int ans = 0;

 public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    dfs(digits, 0, n);

    return ans;
  }

  void dfs(vector<string>& d, long num, int n) {
    for (int i = 0; i < d.size(); ++i) {
      num = num * 10 + (d[i][0] - '0');

      if (num > n) {
        return;
      }

      ++ans;

      dfs(d, num, n);

      num /= 10;
    }
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    string s = to_string(n);

    int ans = 0;

    for (int i = 1; i < s.size(); ++i) {
      ans += pow(digits.size(), i);
    }

    for (int i = 0; i < s.size(); ++i) {
      bool cur_same = false;

      for (auto d : digits) {
        if (d[0] < s[i]) {
          ans += pow(digits.size(), s.size() - i - 1);
        } else if (d[0] == s[i]) {
          cur_same = true;
        }
      }

      if (!cur_same) {
        return ans;
      }
    }

    return ans + 1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 25.11%

class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    unordered_set<int> st;

    for (auto d : digits) {
      st.insert(d[0] - '0');
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
      bool flag = true;

      int t = i;

      while (t > 0) {
        if (st.find(t % 10) == st.end()) {
          flag = false;
          break;
        }

        t /= 10;
      }

      if (flag) {
        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded
// 2021.12.18 at 茗筑美嘉