class Solution {
 public:
  int findLatestStep(vector<int>& arr, int m) {
    int n = arr.size();

    int ans = n;

    vector<int> g(n, 1);

    while (!arr.empty()) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (g[i] == 1) {
          ++cnt;
        } else if (cnt == m) {
          return arr.size();
        } else {
          cnt = 0;
        }
      }

      if (cnt == m) {
        return arr.size();
      }

      g[arr.back() - 1] = 0;
      arr.pop_back();
    }

    return -1;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int findLatestStep(vector<int>& arr, int m) {
    vector<vector<int>> secs;

    int n = arr.size();

    secs.push_back({0, n + 1});

    while (!arr.empty()) {
      vector<vector<int>> tmp = secs;

      for (int i = 0; i < tmp.size(); ++i) {
        if (tmp[i][1] - tmp[i][0] - 1 == m) {
          return arr.size();
        }

        if (arr.back() >= tmp[i][0] && arr.back() <= tmp[i][1]) {
          secs.erase(secs.begin() + i);
          secs.push_back({tmp[i][0], arr.back()});
          secs.push_back({arr.back(), tmp[i][1]});
        }
      }

      arr.pop_back();
    }

    return -1;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int findLatestStep(vector<int>& arr, int m) {
    int n = arr.size();

    if (m == n) {
      return n;
    }

    int ans = -1;

    vector<int> length(arr.size() + 2);

    for (int i = 0; i < n; ++i) {
      int a = arr[i];

      int left = length[a - 1];
      int right = length[a + 1];

      length[a] = left + right + 1;

      length[a + right] = length[a];
      length[a - left] = length[a];

      if (left == m || right == m) {
        ans = i;
      }
    }

    return ans;
  }
};
// Runtime: 268 ms, faster than 97.91%
// Memory Usage: 79.8 MB, less than 5.09%