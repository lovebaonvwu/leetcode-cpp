class Solution {
 public:
  int longestPalindrome(vector<string>& words) {
    vector<vector<int>> mat(26, vector<int>(26));

    int ans = 0;

    for (auto& w : words) {
      int i = w[0] - 'a', j = w[1] - 'a';

      if (mat[j][i] > 0) {
        ans += 4;
        --mat[j][i];
      } else {
        ++mat[i][j];
      }
    }

    for (int i = 0; i < mat.size(); ++i) {
      if (mat[i][i] > 0) {
        ans += 2;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 212 ms, faster than 99.80%
// Memory Usage: 168.3 MB, less than 20.21%
// 2022.1.11 at 奥盛大厦