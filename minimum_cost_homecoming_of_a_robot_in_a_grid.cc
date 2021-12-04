class Solution {
 public:
  int minCost(vector<int>& startPos,
              vector<int>& homePos,
              vector<int>& rowCosts,
              vector<int>& colCosts) {
    int ans = 0;

    for (int i = min(startPos[0], homePos[0]);
         i <= max(startPos[0], homePos[0]); ++i) {
      ans += rowCosts[i];
    }
    ans -= rowCosts[startPos[0]];

    for (int j = min(startPos[1], homePos[1]);
         j <= max(startPos[1], homePos[1]); ++j) {
      ans += colCosts[j];
    }
    ans -= colCosts[startPos[1]];

    return ans;
  }
};
// Runtime: 172 ms, faster than 75.46%
// Memory Usage: 150 MB, less than 27.65%
// 2021.12.4 at 茗筑美嘉

class Solution {
 public:
  int minCost(vector<int>& startPos,
              vector<int>& homePos,
              vector<int>& rowCosts,
              vector<int>& colCosts) {
    int ans = 0;

    int x = startPos[0], y = homePos[0];

    while (x != y) {
      x += x < y ? 1 : -1;

      ans += rowCosts[x];
    }

    x = startPos[1], y = homePos[1];

    while (x != y) {
      x += x < y ? 1 : -1;

      ans += colCosts[x];
    }

    return ans;
  }
};
// Runtime: 176 ms, faster than 67.57%
// Memory Usage: 149.9 MB, less than 27.65%
// 2021.12.4 at 茗筑美嘉