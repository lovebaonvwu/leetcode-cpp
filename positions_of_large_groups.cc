class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> ans;

    int i = 0;
    int j = 0;
    int n = S.size();

    while (j < n) {
      while (S[i] == S[j]) {
        ++j;
      }

      if (j - i > 2) {
        ans.push_back({i, j - 1});
      }

      i = j;
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 70.41%
// Memory Usage: 9.4 MB, less than 40.00%

class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> ans;

    S.append("*");

    int begin = 0;
    int cnt = 1;

    for (int i = begin + 1; i < S.size(); ++i) {
      if (S[i] == S[begin]) {
        ++cnt;
      } else {
        if (i - begin > 2) {
          ans.push_back({begin, i - 1});
        }

        cnt = 1;
        begin = i;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 70.41%
// Memory Usage: 9.3 MB, less than 60.00%