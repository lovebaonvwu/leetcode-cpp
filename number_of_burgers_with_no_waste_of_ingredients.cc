class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    vector<int> ans;

    if ((tomatoSlices - 2 * cheeseSlices) % 2 != 0) {
      return ans;
    }

    int jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
    int small = cheeseSlices - jumbo;

    if (jumbo < 0 || small < 0) {
      return ans;
    }

    ans.push_back(jumbo);
    ans.push_back(small);

    return ans;
  }
};
// Runtime: 4 ms, faster than 86.52%
// Memory Usage: 8.4 MB, less than 100.00%

class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    int burgers = cheeseSlices;

    for (int jumbo = 0; jumbo <= burgers; ++jumbo) {
      int small = burgers - jumbo;

      if (4 * jumbo + 2 * small == tomatoSlices) {
        return {jumbo, small};
      }
    }

    return {};
  }
};
// Runtime: 1168 ms, faster than 5.80%
// Memory Usage: 8.3 MB, less than 100.00%

class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if (tomatoSlices % 2 != 0 || cheeseSlices > tomatoSlices / 2) {
      return {};
    }

    int n = tomatoSlices / 2;

    for (int i = 0; i <= n; ++i) {
      int ts = tomatoSlices - 4 * i;
      int cs = cheeseSlices - i;

      if (ts % 2 != 0) {
        continue;
      }

      for (int j = 0; j <= ts; ++j) {
        if (2 * j == ts && j == cs) {
          return {i, j};
        }
      }
    }

    return {};
  }
};
// Time Limit Exceeded