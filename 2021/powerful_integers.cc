class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> st;

    for (int i = 0; i < log2(1000000) && pow(x, i) < bound; ++i) {
      for (int j = 0; j < log2(1000000) && pow(y, j) < bound; ++j) {
        int n = pow(x, i) + pow(y, j);
        if (n <= bound) {
          st.insert(n);
        }
      }
    }

    return vector<int>(st.begin(), st.end());
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.8 MB, less than 100.00%

class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> st;

    for (int i = 1; i < bound; i *= x) {
      for (int j = 1; i + j <= bound; j *= y) {
        st.insert(i + j);

        if (y == 1) {
          break;
        }
      }

      if (x == 1) {
        break;
      }
    }

    return vector<int>(st.begin(), st.end());
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 100.00%

class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> st;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      int n = pow(x, i) + pow(y, j);
      if (n <= bound) {
        st.insert(n);

        if (x > 1) {
          q.push({i + 1, j});
        }

        if (y > 1) {
          q.push({i, j + 1});
        }
      }
    }

    return vector<int>(st.begin(), st.end());
  }
};
// Runtime: 4 ms, faster than 23.34%
// Memory Usage: 6.9 MB, less than 100.00%