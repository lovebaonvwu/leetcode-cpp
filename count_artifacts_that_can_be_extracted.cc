class Solution {
 public:
  int digArtifacts(int n,
                   vector<vector<int>>& artifacts,
                   vector<vector<int>>& dig) {
    vector<vector<bool>> digged(n, vector<bool>(n));

    for (auto& d : dig) {
      digged[d[0]][d[1]] = true;
    }

    int ans = 0;

    for (auto& a : artifacts) {
      auto& top = a[0];
      auto& left = a[1];
      auto& bottom = a[2];
      auto& right = a[3];

      bool notDigged = false;
      for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
          if (digged[i][j] == false) {
            notDigged = true;
            break;
          }
        }

        if (notDigged) {
          break;
        }
      }

      if (!notDigged) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 420 ms, faster than 30.44%
// Memory Usage: 146.2 MB, less than 8.70%
// 2022.3.14 at 奥盛大厦