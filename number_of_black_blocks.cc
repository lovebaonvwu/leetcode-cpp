class Solution {
 public:
  vector<long long> countBlackBlocks(int m,
                                     int n,
                                     vector<vector<int>>& coordinates) {
    vector<long long> ans(5);
    set<pair<int, int>> st;
    for (auto& cor : coordinates) {
      st.insert({cor[0], cor[1]});
    }

    function<int(int, int)> count = [&](int i, int j) -> int {
      int cnt = 0;
      cnt += st.count({i, j});
      cnt += st.count({i, j + 1});
      cnt += st.count({i + 1, j});
      cnt += st.count({i + 1, j + 1});
      return cnt;
    };

    for (int i = 0; i < m - 1; ++i) {
      for (int j = 0; j < n - 1; ++j) {
        ++ans[count(i, j)];
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<long long> countBlackBlocks(int m,
                                     int n,
                                     vector<vector<int>>& coordinates) {
    map<pair<int, int>, int> cnt;
    for (auto& coordinate : coordinates) {
      int i = coordinate[0];
      int j = coordinate[1];

      if (i - 1 >= 0 && j - 1 >= 0) {
        ++cnt[{i - 1, j - 1}];
        ++cnt[{i - 1, j}];
        ++cnt[{i, j - 1}];
        ++cnt[{i, j}];
      } else if (i - 1 >= 0) {
        ++cnt[{i - 1, j}];
        ++cnt[{i, j}];
      } else if (j - 1 >= 0) {
        ++cnt[{i, j - 1}];
        ++cnt[{i, j}];
      } else {
        ++cnt[{i, j}];
      }
    }

    vector<long long> ans(5);
    for (auto c : cnt) {
      if (c.first.first == m - 1 || c.first.second == n - 1) {
        continue;
      }
      ++ans[c.second];
    }

    ans[0] = 1LL * (m - 1) * (n - 1) - accumulate(ans.begin(), ans.end(), 0LL);

    return ans;
  }
};
// 776ms
// 249.76mb