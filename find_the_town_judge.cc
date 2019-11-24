class Solution {
 public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> cnt(N + 1, 0);

    for (auto& t : trust) {
      --cnt[t[0]], ++cnt[t[1]];
    }

    for (int i = 1; i <= N; ++i) {
      if (cnt[i] == N - 1) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 148 ms, faster than 94.79%
// Memory Usage: 42.3 MB, less than 100.00%

class Solution {
 public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> t(N + 1, 0);
    vector<int> cnt(N + 1, 0);

    for (auto& v : trust) {
      t[v[0]] = 1;
      cnt[v[1]]++;
    }

    for (int i = 1; i <= N; ++i) {
      if (t[i] == 0 && cnt[i] == N - 1) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 164 ms, faster than 59.38%
// Memory Usage: 42.4 MB, less than 87.50%