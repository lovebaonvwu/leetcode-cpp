class Solution {
  int moves(int n, int x, int y, int p, string& s) {
    int cnt = 0;

    for (int i = p; i < s.size(); ++i) {
      if (s[i] == 'L') {
        y -= 1;
      } else if (s[i] == 'R') {
        y += 1;
      } else if (s[i] == 'U') {
        x -= 1;
      } else if (s[i] == 'D') {
        x += 1;
      }

      if (x < 0 || x >= n || y < 0 || y >= n) {
        break;
      }

      ++cnt;
    }

    return cnt;
  }

 public:
  vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    vector<int> ans(s.size());

    for (int i = 0; i < s.size(); ++i) {
      ans[i] = moves(n, startPos[0], startPos[1], i, s);
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 64.29%
// Memory Usage: 10.2 MB, less than 28.57%
// 2021.12.27 at 奥盛大厦