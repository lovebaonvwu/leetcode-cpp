class Solution {
 public:
  int countTriples(int n) {
    unordered_set<int> st;

    for (int i = 1; i <= n; ++i) {
      st.insert(i * i);
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == j) {
          continue;
        }

        if (st.find(i * i + j * j) != st.end()) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 50.88%
// Memory Usage: 6.8 MB, less than 12.02%
// 2021.8.16 at 奥盛大厦

class Solution {
 public:
  int countTriples(int n) {
    vector<int> t(n * n + 1);

    for (int i = 1; i <= n; ++i) {
      t[i * i] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i; i * i + j * j <= n * n; ++j) {
        ans += t[i * i + j * j] * 2;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 97.69%
// Memory Usage: 15.4 MB, less than 5.29%
// 2021.8.16 at 奥盛大厦